#ifndef _OSDETECT_H
#define _OSDETECT_H
/**\~\file
 * Functions for OS & features detections.
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PLATFORM_UNKNOWN 0  ///< \~ Denotes an unknown platform.
	                        ///< This macro is used to mark that the OS in
                            ///< question is not recognised.
#define PLATFORM_WINDOWS 2  ///< \~ Denotes a Windows platform.
                            ///< This macro is used if the current application
                            ///< is running on a Microsoft Windows system.
#define PLATFORM_APPLE   3  ///< \~ Denotes an Apple platform.
                            ///< This macro is used if the current application
                            ///< is running on an Apple developed system. This
                            ///< is usually a Mac OS.
#define PLATFORM_UNIX    1  ///< \~ Denotes a UNIX platform.
                            ///< This macro is used if the current application
                            ///< is running on a UNIX based system, other than
                            ///< an Apple system.

	int sys_platform();

#ifdef __cplusplus
}
#endif

#endif//_OSDETECT_H

