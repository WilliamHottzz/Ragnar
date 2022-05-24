#pragma once

#include <windows.h>
#include <iostream>

int SuspendProcess(DWORD pid);
int ContinueProcess(DWORD pid);
int ProcessArchitecture(DWORD pid);
