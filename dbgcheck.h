#pragma once
#include <iostream>
#include <windows.h>
#include <cinttypes>
#include <winternl.h>
#include <stdio.h>
#include <Tlhelp32.h>
#include "outputresponse.h"


enum DebuggerErrorCodes
{
	CheckFailed,
	InvalidHandle,
	ImportDllFailed,
	FailedQuery,
	RanToEnd
};

enum DebuggerCodes
{
	Haribo = 69,
	Fish
};



int TargetUnderDebugger(HANDLE process);
int TargetDebugPortCheck(HANDLE process);
//	int BreakDebugger(HANDLE process);
