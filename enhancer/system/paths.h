#ifndef _PATHS_H
#define _PATHS_H
/**\addtogroup enh-sys
 * @{
 * \~English \file
 * System wide path retrieval functions.
 * These functions will retrieve the path for the requested use, for instance,
 * if you want to access a user configuration, or you want to retrieve program
 * data files.
 */

/**\~English
 * \def DIRSEP
 * Directory separator string. The directory separator, that the system uses.
 * \hideinitializer
 * \def DIRSEPLEN
 * Directory separator length.
 * \hideinitializer
 * \note This macro is provided for convenience. It is possible that will be
 * removed from future version.
 */
#ifdef _WIN32
#define DIRSEP "\\"
#define DIRSEPLEN 1
#else
#define DIRSEP "/"
#define DIRSEPLEN 1
#endif

#define GLOBAL_DATA_PATH   0x000 ///< \~English System data flag.
                                 ///< Requests the system's data path
                                 ///< from sys_getpath(int).
								 ///< \hideinitializer
#define GLOBAL_CONFIG_PATH 0x001 ///< \~English System configure flags.
                                 ///< Requests the system's configuration
                                 ///< path from sys_getpath(int).
								 ///< \hideinitializer
#define LOCAL_STATE_DATA   0x011
								 ///< \hideinitializer
#define USER_DATA_PATH     0x100 ///< \~English User data flag.
                                 ///< Requests the user's data path
                                 ///< from sys_getpath(int).
								 ///< \hideinitializer
#define USER_CONFIG_PATH   0x101 ///< \~English User config flag.
                                 ///< Requests the user's configuration
                                 ///< path from sys_getpath(int).
								 ///< \hideinitializer
#define SHARED_STATE_DATA  0x111
								 ///< \hideinitializer

#ifdef __cplusplus
extern "C" {
#endif

/**\~English
 * Name of the configuration folder. This will be the look-up name of the global
 * configuration folder that the application will look for, where applicable.
 * This is needed in such environment, where the application data is stored
 * together with other resources. If you don't want to organise these kind of
 * files, then set this value to `NULL`.
 * \par Recommended value
 * `"config"`—In addition, you may use any other folder name that is consist
 * *only* from ASCII (0x00–0x7F) characters.
 * \par Resulting path
 * **Under developement**
 * The result of `sys_getpath(int)` will be suffixed with this string separated
 * with the system's default directory separator string, `DIRSEP`. For example,
 * on a Mac OS X with a value of `config`, it would be something like
 * `/Application/My.app/Contents/Resources/config`.
 * \par Effected systems
 * **Under developement**
 * \warning This variable makes no change after a
 * `sys_getpath(GLOBAL_CONFIG_PATH)` call.
 */
extern char* sys_conf_dir;
/**\~English
 * Name of the data folder. This will be the look-up name of the global data
 * folder that the application will look for, where applicable.
 * This is needed in such environment, where the application data is stored
 * together with other resources. If you don't want to organise these kind of
 * files, then set this value to `NULL`.
 * \par Default value and recommendation
 * `"data"`—In addition, you may use any other folder name that is consist
 * *only* from ASCII (0x00–0x7F) characters.
 * \par Resulting path
 * **Under developement**
 * The result of `sys_getpath(int)` will be suffixed with this string separated
 * with the system's default directory separator string, `DIRSEP`. For example,
 * on a Mac OS X with a value of `data`, it would be something like
 * `/Application/My.app/Contents/Resources/data`.
 * \par Effected systems
 * **Under developement**
 * \warning This variable makes no change after a
 * `sys_getpath(GLOBAL_DATA_PATH)` call.
 */
extern char* sys_data_dir;

/**\~English
 * Retrieves the requested folder.
 * Retrieves the absolute path for the application with one of the
 * defined macro.
 * \param[in]  path The kind of system path that is desired to be
 * retrieved.
 * \returns The absolute path for the desired purpose.
 */
char* sys_getpath(int path);

/// @}

#ifdef __cplusplus
}
#endif

#endif//_PATHS_H

