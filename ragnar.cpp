
#include <iostream>
#include <windows.h>
#include <processthreadsapi.h>
#include "dbgcheck.h"
#include "error.h"
#include "ragnar.h"
#include "protection.h"
#include "outputresponse.h"


int main(int argc, char* pid[])
{
    VERIFY(argc != 1);


    ProtectMe trojan;
    DebugMessage DbgMessage;

    if (trojan.xkGTD04())
    {
        exit(StartedUnderDebugger);
    }

    DWORD processid = atoi(pid[1]);
    DWORD err = NULL;

    HANDLE process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, processid); 

    if(process != INVALID_HANDLE_VALUE)
    {
        while (1)
        {
            if (TargetUnderDebugger(process) == Haribo)
            {
                DbgMessage.Print(DbgMessage.DebuggerFoundRemote);
            }

            Sleep(2000.7);
            TargetDebugPortCheck(process);
        }
    }
    else
    {
        return FailedOpeningProcess;
    }
}
