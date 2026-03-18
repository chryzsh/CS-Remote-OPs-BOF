# BOF Code Review Summary (Sorted By BOF)

**Original Review Date:** 2025-11-15  
**Source Branch:** `claude/bof-code-review-01S7a2WZrCSo8vWweBPX4ZjR`  
**Reviewer:** Claude Code Review

This version is organized by BOF so you can remediate one BOF at a time.

---

## How To Work This

1. Start at the top of **P1 (Critical/Blocker)**.
2. Fix all unchecked checklist items in one BOF section.
3. Build/test that BOF.
4. Mark the BOF section done and move to the next.

Legend:
- `[ ]` still open
- `[x]` appears resolved on current HEAD (kept for audit/history)
- `STALE` means original line refs no longer match current code and need re-baselining

---

## P1 (Critical / Blocker) BOFs

### [x] ProcessDestroy
- Severity: Closed (false positive)
- Findings:
  - [x] `src/Remote/ProcessDestroy/entry.c:159` `SYSTEM_HANDLE_ENTRY` is valid from SDK `winternl.h`.
    Context: `SYSTEM_HANDLE_ENTRY`/`PSYSTEM_HANDLE_INFORMATION` plus `OwnerPid/HandleValue/AccessMask` are defined by toolchain headers and compile successfully.
  - [x] `src/Remote/ProcessDestroy/entry.c:30` local `_SYSTEM_HANDLE` typedef is unused duplicate.
    Context: dead code cleanup candidate only; it does not indicate a runtime or compile blocker.

### [x] ProcessListHandles
- Severity: Closed (false positive)
- Findings:
  - [x] `src/Remote/ProcessListHandles/entry.c:125` `SYSTEM_HANDLE_ENTRY` usage is valid for current SDK headers.
    Context: field access patterns match the `winternl.h` definition used by this toolchain.
  - [x] `src/Remote/ProcessListHandles/entry.c:38` local `_SYSTEM_HANDLE` typedef is unused duplicate.
    Context: same cleanup-only issue as `ProcessDestroy`; no functional mismatch.

### [ ] adcs_request
- Severity: Critical
- Findings:
  - [ ] `src/Remote/adcs_request/adcs_request.c:439` hardcoded debug file write (`debug.csr`).
    Context: CSR material is written to disk unconditionally (`CreateFileA`/`WriteFile`), creating an OPSEC artifact and possible sensitive-data exposure.
  - [ ] `src/Remote/adcs_request/adcs_request.c:102` incorrect function label in error macro.
    Context: failure is from `CoCreateInstance(CLSID_CX509PrivateKey)` but message says `CLSID_CCspInformations`, which misleads debugging.
  - [ ] `src/Remote/adcs_request/adcs_request.c:128` incorrect function label in error macro.
    Context: failure check after `put_CspInformations` reports `put_ExportPolicy`, again obscuring root-cause triage.

### [ ] adcs_request_on_behalf
- Severity: Critical
- Findings:
  - [ ] `src/Remote/adcs_request_on_behalf/entry.c:173` certificate is added to current-user store.
    Context: `CertAddCertificateContextToStore(..., "MY", ...)` persists material that should be ephemeral for this operation.
  - [ ] `src/Remote/adcs_request_on_behalf/entry.c:289` wrong length source for certificate context creation.
    Context: it builds cert context from `strCert` but uses `SysStringByteLen(strPFX)`; mismatched length can truncate/overread certificate bytes.
  - [ ] `src/Remote/adcs_request_on_behalf/entry.c:43` format string drops `GetLastError()` value.
    Context: macro passes an extra argument without `%lu`, so error code is lost from output.
  - [ ] `src/Remote/adcs_request_on_behalf/entry.c:151` invalid format string (`%` tail).
    Context: trailing `%` invokes undefined formatting behavior and can break output path reliability.

### [x] adduser
- Severity: Critical (resolved on current branch)
- Findings:
  - [x] `src/Remote/adduser/entry.c:41` server-name empty check is now guarded against NULL.
    Context: malformed/truncated task data no longer reaches an unchecked `lpswzServerName[0]` dereference.

### [x] addusertogroup
- Severity: Critical (resolved on current branch)
- Findings:
  - [x] `src/Remote/addusertogroup/entry.c:59` `bofstart()` now executes before validation `goto go_end` paths.
    Context: output/cleanup path is initialized before argument-validation exits.

### [x] enableuser
- Severity: Critical (resolved on current branch)
- Findings:
  - [x] `src/Remote/enableuser/entry.c:61` host pointer now guarded with NULL check and empty-string normalization.
    Context: malformed/truncated task data no longer reaches an unchecked dereference.
  - [x] `src/Remote/enableuser/entry.c:62` username pointer now validated after `bofstart()` with `goto go_end` on failure.
    Context: missing username is caught and reported before reaching `EnableUser` or `internal_printf`.

### [ ] get_priv
- Severity: Critical/High
- Findings:
  - [ ] `src/Remote/get_priv/entry.c:114` `priv[0]` dereferenced without NULL check.
    Context: `priv` comes from `BeaconDataExtract` and is read before validation, creating a direct NULL-deref path.
  - [ ] `src/Remote/get_priv/entry.c:121` privilege name is forwarded without strict validation.
    Context: any arbitrary string is passed to `SetPrivilege`; failures are logged but pre-validation/filtering is absent.

### [x] ghost_task
- Severity: Critical (resolved on current branch)
- Findings:
  - [x] `src/Remote/ghost_task/ghost_task.c:271` weekly BOF path no longer overwrites `time` with day string.
    Context: weekly parsing now preserves time for HH:MM parsing and keeps day extraction separate.

### [ ] global_unprotect
- Severity: Critical
- Findings:
  - [ ] `src/Remote/global_unprotect/entry.c:311` unsafe `strcat` to path buffer.
    Context: append assumes destination has enough space; no length bound is enforced.
  - [ ] `src/Remote/global_unprotect/entry.c:312` second unsafe `strcat` with same risk.
    Context: duplicate pattern on roaming path; both paths can overflow if base env path is long.
  - [ ] `src/Remote/global_unprotect/entry.c:124` direct `LoadLibraryA` in BOF path.
    Context: bypasses BOF-friendly import/dynamic-load conventions and increases runtime compatibility risk.
  - [ ] `src/Remote/global_unprotect/entry.c:128` repeated direct loader usage.
    Context: same issue across multiple DLL loads, not a one-off exception.

### [x] make_token_cert
- Severity: Critical (resolved on current branch)
- Findings:
  - [x] `src/Remote/make_token_cert/entry.c:78` token-handle lifecycle issue addressed.
    Context: `LogonUserW` token is now handled with explicit cleanup in resolved paths.
  - [x] `src/Remote/make_token_cert/entry.c:106` certificate blob extraction now validated before use.
    Context: task-data pointer handling now guards malformed/empty extraction cases.
  - [x] `src/Remote/make_token_cert/entry.c:107` password extraction now validated before use.
    Context: pointer validation closes the null/malformed tasking crash path for password handling.

### [ ] ntqueueapcthread
- Severity: Critical
- Findings:
  - [ ] `src/Injection/ntqueueapcthread/entry.c:45` syscall stubs are allocated but never freed.
    Context: stubs obtained by `GetSyscallStub` (`NtCreateSection`..`NtClose`) have no corresponding `VirtualFree` cleanup in `end:`.
  - [ ] `src/Injection/ntqueueapcthread/entry.c:177` cleanup omits stub and module teardown.
    Context: `end:` only closes section handle; no per-stub free and no `_FreeLibrary(hNTDLL)` call.

### [x] reg_save
- Severity: Closed (false positive)
- Findings:
  - [x] `src/Remote/reg_save/entry.c:50` output path is accepted directly from task data.
    Context: intentional operator-controlled behavior for this BOF; destination path selection is part of the tool’s purpose.
  - [x] `src/Remote/reg_save/entry.c:18` output path is passed to `RegSaveKeyExA` without BOF-side path restrictions.
    Context: treated as expected behavior; OS ACL/token checks enforce write permission and errors are handled.

### [x] reg_set
- Severity: Closed (resolved + FP/Won't Fix)
- Findings:
  - [x] `src/Remote/reg_set/entry.c:59` wrong variable nullification issue fixed.
    Context: remote/local key cleanup state is now consistent after closing handles.
  - [x] `src/Remote/reg_set/entry.c:109` QWORD reads 32-bit source value (FP / Won't Fix).
    Context: caller-side tasking encodes QWORD as 32-bit integer and BOF zero-extends by design due to Sleep integer packing limits.
  - [x] `src/Remote/reg_set/entry.c:111` 4-byte copy into QWORD buffer (FP / Won't Fix).
    Context: paired with line 109 by design for 32-bit encoded input; upper 32 bits intentionally padded with zeros.
  - [x] `src/Remote/reg_set/entry.c:110` temporary QWORD allocation leak fixed.
    Context: BOF path now releases temporary allocation after use.

### [ ] sc_create
- Severity: Critical
- Findings:
  - [ ] `src/Remote/sc_create/entry.c:23` memcpy uses `newdesc` without NULL/length guard.
    Context: `newdesc` comes from argument extraction; NULL with nonzero `desclen` would dereference invalid memory.
  - [ ] `src/Remote/sc_create/entry.c:16` description buffer alloc has no explicit NUL termination after copy.
    Context: `desclen+1` is allocated, but copied bytes are not terminated before API consumption.

### [ ] sc_description
- Severity: Critical
- Findings:
  - [ ] `src/Remote/sc_description/entry.c:22` memcpy uses `newdesc` without NULL/length guard.
    Context: same pattern as `sc_create`; malformed extraction can crash before SCM call.
  - [ ] `src/Remote/sc_description/entry.c:15` alloc/copy path does not enforce final NUL byte.
    Context: service-description API receives heap buffer whose trailing byte is not explicitly set.

### [ ] sc_failure
- Severity: Critical/High
- Findings:
  - [ ] `src/Remote/sc_failure/entry.c:35` variable-length array `SC_ACTION actions[cActions]` is user-sized.
    Context: large `cActions` can exhaust BOF stack budget and destabilize beacon thread.
  - [ ] `src/Remote/sc_failure/entry.c:94` `OpenProcessToken` result is unchecked.
    Context: privilege path continues even if token acquisition fails, producing silent misconfiguration.
  - [ ] `src/Remote/sc_failure/entry.c:100` `AdjustTokenPrivileges` result is unchecked.
    Context: code assumes privilege enablement succeeded and attempts privileged config regardless.

### [ ] setthreadcontext
- Severity: Critical
- Findings:
  - [ ] `src/Injection/setthreadcontext/entry.c:95` thread IP is overwritten to shellcode address with no restore plan.
    Context: if shellcode returns or faults, original execution context is lost and target thread stability is at risk.
  - [ ] `src/Injection/setthreadcontext/entry.c:121` source comment confirms missing restore/wait strategy.
    Context: TODO-style note indicates incomplete control-flow finalization in production path.
  - [ ] `src/Injection/setthreadcontext/entry.c:65` remote shellcode buffer is allocated but never freed.
    Context: `lpRemoteBuffer` has no `VirtualFreeEx` cleanup in `end:`.

### [ ] setuserpass
- Severity: Critical
- Findings:
  - [ ] `src/Remote/setuserpass/entry.c:38` computer pointer extracted without validation.
    Context: malformed task packet can produce NULL pointer consumed by logging/API calls.
  - [ ] `src/Remote/setuserpass/entry.c:39` user pointer extracted without validation.
    Context: same unchecked extraction pattern as computer pointer.
  - [ ] `src/Remote/setuserpass/entry.c:40` password pointer extracted without validation.
    Context: no defensive guard before printing and password set call.
  - [ ] `src/Remote/setuserpass/entry.c:47` plaintext password logged.
    Context: emits full credential material into operator output and logs.

### [ ] slack_cookie
- Severity: Critical
- Findings:
  - [ ] `src/Remote/slack_cookie/entry.c:71` direct `LoadLibraryA("kernel32")` in BOF path.
    Context: bypasses expected BOF import-resolution model and introduces avoidable runtime variability.
  - [ ] `src/Remote/slack_cookie/entry.c:77` direct `GetProcAddress` for `ReadProcessMemory`.
    Context: same manual resolution pattern repeats; no BOF-friendly abstraction used.
  - [ ] `src/Remote/slack_cookie/entry.c:129` second manual `LoadLibraryA` path in same BOF.
    Context: duplicates the anti-pattern in `GetProcessMemory` routine.
  - [ ] `src/Remote/slack_cookie/entry.c:136` second manual `GetProcAddress` path.
    Context: repeated direct resolver use compounds maintenance/runtime risk.

### [ ] tooltip
- Severity: Critical
- Findings:
  - [ ] `src/Injection/tooltip/entry.c:52` syscall stubs are allocated but never explicitly freed.
    Context: `NtAllocateVirtualMemory/NtReadVirtualMemory/NtWriteVirtualMemory/NtFreeVirtualMemory` stubs have no `VirtualFree` teardown.
  - [ ] `src/Injection/tooltip/entry.c:220` cleanup block does not unload stub module or free stubs.
    Context: `end:` only frees remote VFT buffer; local stub/module lifecycle remains unmanaged.

### [ ] unexpireuser
- Severity: Critical
- Findings:
  - [ ] `src/Remote/unexpireuser/entry.c:38` host pointer extracted without validation.
    Context: null/malformed extract can later flow into account APIs unsafely.
  - [ ] `src/Remote/unexpireuser/entry.c:39` user pointer extracted without validation.
    Context: same pattern; no early guard before operational use.

### [ ] uxsubclassinfo
- Severity: Critical
- Findings:
  - [ ] `src/Injection/uxsubclassinfo/entry.c:72` syscall stubs are allocated but never explicitly freed.
    Context: stub pointers from `GetSyscallStub` are not released via `VirtualFree` before return.
  - [ ] `src/Injection/uxsubclassinfo/entry.c:234` cleanup handles remote allocations but not local stub/module teardown.
    Context: `end:` frees remote buffers and process handle only; stub memory lifecycle is missing.

---

## P2 (High Priority) BOFs

### [ ] clipboard
- Severity: High
- Findings:
  - [ ] `src/Injection/clipboard/entry.c:166` incorrect free flags (`MEM_RELEASE | MEM_DECOMMIT`).
    Context: combining these flags is invalid for `VirtualFreeEx`; release semantics become undefined/failing.

### [ ] conhost
- Severity: High
- Findings:
  - [ ] `src/Injection/conhost/entry.c:299` incorrect free flags (`MEM_RELEASE | MEM_DECOMMIT`).
    Context: same invalid flag combination as clipboard; should be one mode per call.

### [ ] ctray
- Severity: High
- Findings:
  - [ ] `src/Injection/ctray/entry.c:233` incorrect free flags (`MEM_RELEASE | MEM_DECOMMIT`).
    Context: repeated invalid `VirtualFreeEx` parameterization in cleanup path.

### [ ] dde
- Severity: High
- Findings:
  - [ ] `src/Injection/dde/entry.c:183` `DdeInitializeA` return code is ignored.
    Context: trigger path proceeds even if DDE subsystem initialization fails.
  - [ ] `src/Injection/dde/entry.c:186` `DdeConnectList` result is not validated.
    Context: code calls `DdeDisconnectList` unconditionally, potentially on invalid handle.
  - [ ] `src/Injection/dde/entry.c:187` `DdeDisconnectList`/`DdeUninitialize` errors are ignored.
    Context: cleanup/trigger reliability is opaque and failures become silent.

### [ ] kernelcallbacktable
- Severity: High
- Findings:
  - [ ] `src/Injection/kernelcallbacktable/entry.c:361` incorrect free flags (`MEM_RELEASE | MEM_DECOMMIT`).
    Context: same invalid free pattern present in several injection BOFs.

### [ ] ntcreatethread
- Severity: High
- Findings:
  - [ ] `src/Injection/ntcreatethread/entry.c:32` `NtAllocateVirtualMemory` syscall stub is not freed.
    Context: teardown frees other stubs (`NtWriteVirtualMemory`, `NtCreateThreadEx`, etc.) but misses this one, causing per-run leakage.

### [ ] sc_stop
- Severity: High (STALE)
- Findings:
  - [ ] `src/Remote/sc_stop/entry.c:94` original finding says privilege validation gap.
    Context: current code at this line is in dependent-service stop loop, not token privilege logic; re-baseline this finding before remediation.
  - [ ] `src/Remote/sc_stop/entry.c:100` original finding says privilege validation gap.
    Context: current code here is `QueryServiceStatusEx` polling; this appears copied from `sc_failure` findings and is likely stale.

---

## P3 (Remaining BOFs To Triage)

These BOFs were listed as pass/needs-work in the original summary but without explicit blocker line items there.

- [ ] chromeKey
- [ ] createremotethread
- [ ] get_azure_token
- [ ] lastpass
- [ ] office_tokens
- [ ] procdump
- [ ] reg_delete
- [ ] sc_config
- [ ] sc_delete
- [ ] sc_start
- [ ] schtaskscreate
- [ ] schtasksdelete
- [ ] schtasksrun
- [ ] schtasksstop
- [ ] shspawnas
- [ ] shutdown
- [ ] slackKey
- [ ] suspendresume
- [ ] svcctrl

---

## Notes

- File/line references above were revalidated against current local source where possible.
- Items marked `STALE` should be re-triaged before code changes so work is not spent on outdated line mappings.
- Resolved items are intentionally kept in-place for traceability so the historical finding list does not lose provenance.
