#pragma once

#include <windows.h>
#include <iostream>
#include <string>

struct lastError 
{
	DWORD last;
};


void DisplayError(DWORD err);