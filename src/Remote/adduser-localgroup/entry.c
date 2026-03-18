#include "bofdefs.h"

DWORD AddUserToGroup(LPCWSTR lpswzServer, LPCWSTR lpswzUserName, LPCWSTR lpswzGroupName, LPCWSTR lpswzDomainName)
AddUserLocalGroup()
{
    BeaconPrintf(CALLBACK_OUTPUT, "Trying to add %ls to local group instead", mi[0].lgrmi3_domainandname);	
		dwErrorCode = NETAPI32$NetLocalGroupAddMembers(lpswzServer, lpswzGroupName, 3, (LPBYTE)mi, 1);
		if(NERR_Success != dwErrorCode)
		{
			BeaconPrintf(CALLBACK_ERROR, "Unable to add user to local group %lX\n", dwErrorCode);
		}
}
DWORD myFunction(LPCSTR szArg1, DWORD dwArg2) {

	// Error/status tracking
	DWORD dwErrorCode = ERROR_SUCCESS;

	// Handles
	HANDLE hExample = NULL;

	// Configuration structs

	// Loop control
	DWORD i = 0;

	// --- Logic starts here ---

end:
	if (hExample) { KERNEL32$CloseHandle(hExample); }
	return dwErrorCode;
}

VOID go(
	IN PCHAR Buffer,
	IN ULONG Length
) {
	DWORD dwErrorCode = ERROR_SUCCESS;
	datap parser = { 0 };
	BeaconDataParse(&parser, Buffer, Length);

	// Extract arguments - use (LPCSTR) for narrow strings, (LPWSTR) for wide strings
	LPCSTR szArg1 = (LPCSTR)BeaconDataExtract(&parser, NULL);
	DWORD dwArg2 = (DWORD)BeaconDataInt(&parser);

	BeaconPrintf(CALLBACK_OUTPUT, "Running with arg1: %s arg2: %lu\n", szArg1, dwArg2);

	dwErrorCode = myFunction(szArg1, dwArg2);
	if (ERROR_SUCCESS != dwErrorCode) {
		BeaconPrintf(CALLBACK_ERROR, "myFunction failed: %lX\n", dwErrorCode);
	}
	else {
		BeaconPrintf(CALLBACK_OUTPUT, "SUCCESS.\n");
	}
}
