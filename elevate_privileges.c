
#include <stdio.h>
#include <windows.h>

void fail(LPTSTR error_msg) {
	DWORD last_error = GetLastError();

	LPTSTR s;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM, NULL, last_error, 0, (LPTSTR)&s, 0, NULL);

	printf("[FATAL] %s; GetLastError() says: %u (%#x), \"%s\"\n", error_msg, last_error, last_error, s);
	exit(1);
}

HANDLE get_process_security_token() {
	HANDLE process_token;

	if(OpenProcessToken(GetCurrentProcess(), TOKEN_WRITE, &process_token) == FALSE) {
		fail("OpenProcessToken() failed");
	}
	return process_token;
}

LUID get_privilege_value() {
	const LPCTSTR privilege_name = "SeProfileSingleProcessPrivilege";

	LUID privilege_value;

	if(!LookupPrivilegeValue(NULL, privilege_name, &privilege_value)) {
		fail("LookupPrivilegeValue() failed");
	}
	return privilege_value;
}

void elevate_privileges() {

	TOKEN_PRIVILEGES tp;

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = get_privilege_value();
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if(!AdjustTokenPrivileges(get_process_security_token(), FALSE, &tp, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES) NULL, (PDWORD) NULL)) { 
		fail("AdjustTokenPrivileges() failed");
	} 
}
