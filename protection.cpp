#include "protection.h"


/// <summary>
/// Checks block for debugger in startup.
/// </summary>
/// <returns>True if started under debugger.</returns>
bool ProtectMe::xkGTD04()
{
	BOOL found = FALSE;

	__asm	
	{
		xor eax, eax
		mov eax, fs: [0x30]
		mov eax, [eax + 0x02]
		and eax, 0x000000FF
		mov found, eax
	}
	return found;
}


/// <summary>
/// Checks for breakpoint, IF found then program exits.
/// </summary>
void ProtectMe::yZgEuWB()
{
	CONTEXT context = {};
	context.ContextFlags = CONTEXT_DEBUG_REGISTERS;
	if (GetThreadContext(GetCurrentThread(), &context))
	{
		if (context.Dr0 != 0 || context.Dr1 != 0 || context.Dr2 != 0 || context.Dr3 != 0)
		{
			exit(BreakPointDetectedInMain);
		}
	}
}