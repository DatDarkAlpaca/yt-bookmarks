#pragma once
#include <cstdlib>

namespace ytb::platform
{
	inline void ClearConsole()
	{
	#if defined(_WIN32)
		std::system("cls");
	#elif defined(__linux__)
		std::system("clear");
	#endif
	}
}