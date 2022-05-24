#pragma once
#include <iostream>
#include <windows.h>
#include "ragnar.h"

/// <summary>
/// Class of common methods used to protect yourself from STDs
/// </summary>
class ProtectMe
{
public:
	bool xkGTD04(void);
    void yZgEuWB();
};

/*
	#define DBG_PRINTEXCEPTION_WIDE_C 0x4001000A
WCHAR * outputString = L"Any text";
ULONG_PTR args[4] = {0};
args[0] = (ULONG_PTR)wcslen(outputString) + 1;
args[1] = (ULONG_PTR)outputString;
__try
{
    RaiseException(DBG_PRINTEXCEPTION_WIDE_C, 0, 4, args);
    printf("Debugger detected");
}
__except (EXCEPTION_EXECUTE_HANDLER)
{
    printf("Debugger NOT detected");
} 
*/