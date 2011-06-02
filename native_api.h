// native API declarations, ntdll is linked dynamically (versus LoadLibrary())
typedef LONG NTSTATUS;
NTSTATUS WINAPI NtSetSystemInformation(int SystemInformationClass, PVOID SystemInformation, ULONG Length);

//SystemInformationClass values
int SystemMemoryListInformation = 80;

//SystemInfo values
int ClearStandbyPageList = 4;
