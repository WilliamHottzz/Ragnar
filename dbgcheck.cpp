#include "dbgcheck.h"
#include "error.h"



typedef NTSTATUS(NTAPI* pfnNtQueryInformationProcess)
(
    _In_      HANDLE           ProcessHandle,
    _In_      UINT             ProcessInformationClass,
    _Out_     PVOID            ProcessInformation,
    _In_      ULONG            ProcessInformationLength,
    _Out_opt_ PULONG           ReturnLength
);


/// <summary>
/// Checks the process for an active debugger.
/// </summary>
/// <param name="process">Handle of the process.</param>
/// <returns>Returns 69 if remote debugger is found.</returns>
int TargetUnderDebugger(HANDLE process) 
{
	BOOL processdebugged = false;
	DWORD err;
    DebugMessage DbgMessage;
    int result;
	bool completed = CheckRemoteDebuggerPresent(process, &processdebugged);

	if (completed == 0) 
	{
		err = ::GetLastError();
		DisplayError(err);
		return CheckFailed;
	}	
    return result = (processdebugged == true) ? 69 : 77;
}



/// <summary>
/// Checks the process PE block for "BeingDebugged" flag.
/// </summary>
/// <param name="process">Handle of the process.</param>
/// <returns>Returns 69 if debugger is found in PE block.</returns>
int TargetDebugPortCheck(HANDLE process)
{
    NTSTATUS status;
    DWORD isDebuggerPresent = 0;
    DWORD err;
    DebugMessage DbgMessage;
    int founddbger = 0;

    pfnNtQueryInformationProcess NtQueryInformationProcess = NULL;
    HMODULE ntdll = LoadLibrary(TEXT("ntdll.dll")); 

    if (NULL != ntdll)
    {
        NtQueryInformationProcess = (pfnNtQueryInformationProcess)GetProcAddress(ntdll, "NtQueryInformationProcess");

        if (NULL != NtQueryInformationProcess)
        {
            status = NtQueryInformationProcess(process, 0x1E, &isDebuggerPresent, sizeof(DWORD), NULL);

            if (status == 0x00000000 && isDebuggerPresent != 0)
            {
                DbgMessage.Print(DbgMessage.DebuggerFoundInPEB);
                return Haribo;
            }
            else
            {
                return Fish;
            }
        }
        else
        {
            err = ::GetLastError();
            DisplayError(err);
            FreeLibrary(ntdll);
            return FailedQuery;
        }
    }
    else
    {
        err = ::GetLastError();
        DisplayError(err);
        return ImportDllFailed;
    }
    FreeLibrary(ntdll);
    return RanToEnd;
}

