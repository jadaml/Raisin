#ifndef _OSDETECT_H
#define _OSDETECT_H

#ifdef __cplusplus
extern "C" {
#endif

#define PLATFORM_UNKNOWN 0
#define PLATFORM_WINDOWS 2
#define PLATFORM_APPLE   3
#define PLATFORM_UNIX    1

	int sys_platform();

#ifdef __cplusplus
}
#endif

#endif//_OSDETECT_H

