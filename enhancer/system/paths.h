#ifndef _PATHS_H
#define _PATHS_H

#ifdef _WIN32
#define DIRSEP "\\"
#define DIRSEPLEN 1
#else
#define DIRSEP "/"
#define DIRSEPLEN 1
#endif

#define GLOBAL_DATA_PATH   0x00
#define GLOBAL_CONFIG_PATH 0x01
#define USER_DATA_PATH     0x10
#define USER_CONFIG_PATH   0x11

#ifdef __cplusplus
extern "C" {
#endif

extern char* sys_conf_dir;
extern char* sys_data_dir;

char* sys_getpath(int path);

#ifdef __cplusplus
}
#endif

#endif//_PATHS_H

