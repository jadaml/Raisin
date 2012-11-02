#include "osdetect.h"

int sys_platform()
{
#ifdef _WIN32
	return PLATFORM_WINDOWS;
#elif defined __APPLE__
	return PLATFORM_APPLE;
#elif defined unix
	return PLATFORM_UNIX;
#else // At the moment, I don't know about more
	return PLATFORM_UNKNOWN;
#endif
}

