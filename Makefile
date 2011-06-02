EmptyStandbyList: native_api.h elevate_privileges.h elevate_privileges.c main.c
	gcc main.c elevate_privileges.c -lntdll -o EmptyStandbyList
