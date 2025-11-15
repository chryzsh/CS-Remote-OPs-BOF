# BOF Code Review Checklist

**Review Date:** 2025-11-15
**Branch:** claude/bof-code-review-01S7a2WZrCSo8vWweBPX4ZjR
**Reviewer:** Claude Code Review Bot

## Review Criteria Summary

Each BOF is evaluated against 11 key criteria:
1. **Coding Standards** - Naming conventions, commenting, const correctness
2. **Documentation** - Complex logic comments, argument documentation
3. **API Usage** - Dynamic resolution, BOF conventions, no hardcoded addresses
4. **Code Efficiency** - Stack usage ≤4KB, no unnecessary code
5. **Memory Safety & Stability** - Error handling, bounds checking, no leaks
6. **Global Variables** - Non-zero initialization, minimal usage
7. **Execution Characteristics** - Single-threaded, short execution
8. **Argument Parsing** - Correct BeaconData* usage
9. **Compiler Compatibility** - x86/x64 support
10. **Build Configuration** - PIC, stripped symbols
11. **Security Considerations** - Input validation, sensitive data handling

---

## Remote Operations BOFs

### - [ ] adcs_request
- **Description:** Request an enrollment certificate
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/adcs_request/entry.c, src/Remote/adcs_request/adcs_request.c
- **Findings:**

---

### - [ ] adcs_request_on_behalf
- **Description:** Request an enrollment certificate on behalf of another user
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/adcs_request_on_behalf/entry.c
- **Findings:**

---

### - [ ] adduser
- **Description:** Add specified user to a machine
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/adduser/entry.c
- **Findings:**

---

### - [ ] addusertogroup
- **Description:** Add specified user to a group
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/addusertogroup/entry.c
- **Findings:**

---

### - [ ] chromeKey
- **Description:** Decrypt the provided base64 encoded Chrome key
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/chromeKey/entry.c
- **Findings:**

---

### - [ ] enableuser
- **Description:** Enable and unlock the specified user account
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/enableuser/entry.c
- **Findings:**

---

### - [ ] get_azure_token
- **Description:** Attempts to complete an OAuth codeflow grant against azure using saved logins
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/get_azure_token/entry.c
- **Findings:**

---

### - [ ] get_priv
- **Description:** Activate the specified token privilege, more for non-cobalt strike users
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/get_priv/entry.c
- **Findings:**

---

### - [ ] ghost_task
- **Description:** Add/Delete a ghost task
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/ghost_task/entry.c, src/Remote/ghost_task/ghost_task.c
- **Findings:**

---

### - [ ] global_unprotect
- **Description:** Locates and Decrypts GlobalProtect config files converted from GlobalUnProtect
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/global_unprotect/entry.c
- **Findings:**

---

### - [ ] lastpass
- **Description:** Search Chrome, brave memory for LastPass passwords and data
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/lastpass/entry.c
- **Findings:**

---

### - [ ] make_token_cert
- **Description:** Impersonates a user using the altname of a .pfx file
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/make_token_cert/entry.c
- **Findings:**

---

### - [ ] office_tokens
- **Description:** Collect Office JWT Tokens from any Office process
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/office_tokens/entry.c
- **Findings:**

---

### - [ ] procdump
- **Description:** Dump the specified process to the specified output file
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/procdump/entry.c
- **Findings:**

---

### - [ ] ProcessDestroy
- **Description:** Close handle(s) in a process
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/ProcessDestroy/entry.c
- **Findings:**

---

### - [ ] ProcessListHandles
- **Description:** List all open handles in a specified process
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/ProcessListHandles/entry.c
- **Findings:**

---

### - [ ] reg_delete
- **Description:** Delete a registry key
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/reg_delete/entry.c
- **Findings:**

---

### - [ ] reg_save
- **Description:** Save a registry hive to disk
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/reg_save/entry.c
- **Findings:**

---

### - [ ] reg_set
- **Description:** Set / create a registry key
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/reg_set/entry.c
- **Findings:**

---

### - [ ] sc_config
- **Description:** Configure an existing service
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_config/entry.c
- **Findings:**

---

### - [ ] sc_create
- **Description:** Create a new service
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_create/entry.c
- **Findings:**

---

### - [ ] sc_delete
- **Description:** Delete an existing service
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_delete/entry.c
- **Findings:**

---

### - [ ] sc_description
- **Description:** Modify an existing services description
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_description/entry.c
- **Findings:**

---

### - [ ] sc_failure
- **Description:** Configures the actions upon failure of an existing service
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_failure/entry.c
- **Findings:**

---

### - [ ] sc_start
- **Description:** Start an existing service
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_start/entry.c
- **Findings:**

---

### - [ ] sc_stop
- **Description:** Stop an existing service
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/sc_stop/entry.c
- **Findings:**

---

### - [ ] schtaskscreate
- **Description:** Create a new scheduled task (via xml definition)
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/schtaskscreate/entry.c
- **Findings:**

---

### - [ ] schtasksdelete
- **Description:** Delete an existing scheduled task
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/schtasksdelete/entry.c
- **Findings:**

---

### - [ ] schtasksrun
- **Description:** Start a scheduled task
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/schtasksrun/entry.c
- **Findings:**

---

### - [ ] schtasksstop
- **Description:** Stop a running scheduled task
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/schtasksstop/entry.c
- **Findings:**

---

### - [ ] setuserpass
- **Description:** Set a user's password
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/setuserpass/entry.c
- **Findings:**

---

### - [ ] shspawnas
- **Description:** A misguided attempt at injecting code into a newly spawned process
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/shspawnas/entry.c
- **Findings:**

---

### - [ ] shutdown
- **Description:** Shutdown or reboot a local or remote computer, with or without a warning/message
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/shutdown/entry.c
- **Findings:**

---

### - [ ] slack_cookie
- **Description:** Collect the Slack authentication cookie from a Slack process
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/slack_cookie/entry.c
- **Findings:**

---

### - [ ] slackKey
- **Description:** (Note: Found in file listing but not in README table)
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/slackKey/entry.c
- **Findings:**

---

### - [ ] suspendresume
- **Description:** (Note: Found in file listing but not in README table)
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/suspendresume/entry.c
- **Findings:**

---

### - [ ] unexpireuser
- **Description:** Set a user account to never expire
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Remote/unexpireuser/entry.c
- **Findings:**

---

## Injection BOFs
**Note:** These are provided as-is and unsupported per README

### - [ ] clipboard
- **Description:** Injection technique via clipboard
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/clipboard/entry.c
- **Findings:**

---

### - [ ] conhost
- **Description:** Injection technique via conhost
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/conhost/entry.c
- **Findings:**

---

### - [ ] createremotethread
- **Description:** Injection technique via CreateRemoteThread
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/createremotethread/entry.c
- **Findings:**

---

### - [ ] ctray
- **Description:** Injection technique via ctray
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/ctray/entry.c
- **Findings:**

---

### - [ ] dde
- **Description:** Injection technique via DDE
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/dde/entry.c
- **Findings:**

---

### - [ ] kernelcallbacktable
- **Description:** Injection technique via kernel callback table
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/kernelcallbacktable/entry.c
- **Findings:**

---

### - [ ] ntcreatethread
- **Description:** Injection technique via NtCreateThread
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/ntcreatethread/entry.c
- **Findings:**

---

### - [ ] ntqueueapcthread
- **Description:** Injection technique via NtQueueApcThread
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/ntqueueapcthread/entry.c
- **Findings:**

---

### - [ ] setthreadcontext
- **Description:** Injection technique via SetThreadContext
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/setthreadcontext/entry.c
- **Findings:**

---

### - [ ] svcctrl
- **Description:** Injection technique via service control
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/svcctrl/entry.c
- **Findings:**

---

### - [ ] tooltip
- **Description:** Injection technique via tooltip
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/tooltip/entry.c
- **Findings:**

---

### - [ ] uxsubclassinfo
- **Description:** Injection technique via uxsubclassinfo
- **Review Status:** [ ] Not Started / [ ] In Progress / [ ] Complete
- **Files:** src/Injection/uxsubclassinfo/entry.c
- **Findings:**

---

## Summary Statistics
- **Total BOFs:** 50 (38 Remote + 12 Injection)
- **Reviewed:** 0
- **In Progress:** 0
- **Issues Found:** TBD
- **Critical Issues:** TBD
