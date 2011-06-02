
#include <stdio.h>
#include <windows.h>

#include "native_api.h"
#include "elevate_privileges.h"

int main(void) {

	elevate_privileges();

	int system_info = ClearStandbyPageList;

	NTSTATUS ret = NtSetSystemInformation(SystemMemoryListInformation, &system_info, sizeof(system_info));

	printf("NtSetSystemInformation() result: %#x (%u)\n", ret, ret);
	return 0;
}
