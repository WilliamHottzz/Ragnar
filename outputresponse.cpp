#include "outputresponse.h"

void DebugMessage::Print(const std::string& input)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	std::cout << "\n[DEBUGGER]\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << input << std::endl;
};