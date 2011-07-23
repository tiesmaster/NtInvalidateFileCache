NtInvalidateFileCache: native_api.h elevate_privileges.h elevate_privileges.c main.c resource.o
	gcc main.c elevate_privileges.c resource.o -lntdll -o NtInvalidateFileCache

resource.o: resource.rc
	windres resource.rc -o resource.o

.PHONY: clean

clean:
	rm -f NtInvalidateFileCache.exe resource.o
