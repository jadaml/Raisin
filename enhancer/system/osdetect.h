#ifndef _OSDETECT_H
#define _OSDETECT_H
/**\addtogroup enh-sys
 * @{
 * \~English\file
 * Functions for OS & features detections.
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PLATFORM_UNKNOWN 0  ///< \~English Denotes an unknown platform.
                            ///< This macro is used to mark that the OS in
                            ///< question is not recognised.
                            ///< \hideinitializer
#define PLATFORM_WINDOWS 2  ///< \~English Denotes a Windows platform.
                            ///< This macro is used if the current application
                            ///< is running on a Microsoft Windows system.
                            ///< \hideinitializer
#define PLATFORM_APPLE   3  ///< \~English Denotes an Apple platform.
                            ///< This macro is used if the current application
                            ///< is running on an Apple developed system. This
                            ///< is usually a Mac OS.
                            ///< \hideinitializer
#define PLATFORM_UNIX    1  ///< \~English Denotes a UNIX platform.
                            ///< This macro is used if the current application
                            ///< is running on a UNIX based system, other than
                            ///< an Apple system.
                            ///< \hideinitializer

	int sys_platform();

/// @}

#ifdef __cplusplus
}
#endif

#endif//_OSDETECT_H

