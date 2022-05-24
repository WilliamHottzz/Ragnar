#pragma once
#include <iostream>
#include <string>
#include <windows.h>

class DebugMessage
{
public:
	std::string response;
	std::string DebuggerFoundInPEB = "Debugger found in PE block!";
	std::string DebuggerFoundRemote = "Debugger found in remote session!";
	void Print(const std::string& input);
};
