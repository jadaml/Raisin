#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>
#include "paths.h"

char* sys_conf_dir = NULL;
char* sys_data_dir = NULL;

char* _glbl_data_path = NULL;
char* _glbl_conf_path = NULL;
char* _user_data_path = NULL;
char* _user_conf_path = NULL;
char* _cwd = NULL;

char* create_or_die(char* path)
{
	// Check if folder exists, and try to create it or fall back to cwd
	stat dir_stat;
	if (stat(_glbl_data_path, &dir_stat))
		// TODO: Create directory
		;
	else if (!S_ISDIR(dir_stat.st_mode))
		// ERROR
		return NULL;
	return path;
}

char* get_gdata_path()
{
	if (_glbl_data_path != NULL)
		return _glbl_data_path;

	if (_cwd == NULL) _cwd = getcwd(NULL, 0);

#ifdef __APPLE__
	// Data Path can be retrieved with it's own API
#error OS not supported yet.

	// Data Path is defined at compile time with the configure value.
#elif defined unix && defined DATADIR && defined PACKAGE_TARNAME
	_glbl_data_path = new char[strlen(DATADIR) + DIRSEPLEN + strlen(PACKAGE_TARNAME) + 1];

	strcpy(_glbl_data_path, DATADIR);
	strcpy(&(_glbl_data_path[strlen(DATADIR)]), DIRSEP);
	strcpy(&(_glbl_data_path[strlen(DATADIR) + DIRSEPLEN]), PACKAGE_TARNAME);
#elif defined unix
	// TODO: check out $XDG_DATA_DIRS use `basename $0` for PACKAGE_TARNAME
#else
	if (_cwd == NULL) return NULL;

	// The OS might not have a dedicated place to store data files.
	_glbl_data_path = new char[strlen(_cwd) + DIRSEPLEN + 5];
	strcpy(_glbl_data_path, _cwd);
	strcpy(&(_glbl_data_path[strlen(_cwd)]), DIRSEP);
	strcpy(&(_glbl_data_path[strlen(_cwd) + DIRSEPLEN]), "data");
#endif

	if (!create_or_die(_glbl_data_path))
		// We're screwed, but can't die.
		_glbl_data_path = _cwd;

	return _glbl_data_path;
}

char* get_gconf_path()
{
	if (_glbl_conf_path != NULL)
		return _glbl_conf_path;

	if (_cwd == NULL) _cwd = getcwd(NULL, 0);

	// TODO

	if (!create_or_die(_glbl_conf_path))
		_glbl_conf_path = _cwd;

	return _glbl_conf_path;
}

char* get_udata_path()
{
	if (_user_data_path != NULL)
		return _user_data_path;

	if (_cwd == NULL) _cwd = getcwd(NULL, 0);

	// TODO

	if (!create_or_die(_user_data_path))
		_user_data_path = _cwd;
	
	return _user_data_path;
}

char* get_uconf_path()
{
	if (_user_conf_path != NULL)
		return _user_conf_path;

	if (_cwd == NULL) _cwd = getcwd(NULL, 0);

	int start = 0;

#ifdef __APPLE__
	// User's Library folder can be retrieved with API
#error OS not supported yet.

	// __APPLE__
#elif defined _WIN32
	// Windows version dependant.
#error OS not supported yet.

	// _WIN32
#elif defined unix
	// FreeDesktop.org defined a standard sub-folder in the user's home path.
	// Although this wasn't exactly always like that...
	//
	// $XDG_CONFIG_HOME

	char* xdg_config_home = getenv("XDG_CONFIG_HOME");

	if (xdg_config_home && strlen(xdg_config_home) && sys_conf_dir)
	{
		_user_conf_path =
			new char[strlen(xdg_config_home) + strlen(sys_conf_dir) +
			DIRSEPLEN + 1];
		strcpy(_user_conf_path, xdg_config_home); start = strlen(xdg_config_home);
		strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
		strcpy(&_user_conf_path[start], sys_conf_dir);
	}
	else if (xdg_config_home && strlen(xdg_config_home))
	{
#ifdef PACKAGE_TARNAME
		_user_conf_path =
			new char[strlen(xdg_config_home) + strlen(PACKAGE_TARNAME) +
			DIRSEPLEN + 1];
		strcpy(_user_conf_path, xdg_config_home); start = strlen(xdg_config_home);
		strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
		strcpy(&_user_conf_path[start], PACKAGE_TARNAME);
#else
		_user_conf_path = new char[strlen(xdg_config_home)];
		strcpy(_user_conf_path, xdg_config_home);
#endif
	}
	else 
	{
		// I've no respect of variable names in reusing.
		xdg_config_home = getenv("HOME");

		bool home_set;

		// This is very unlikely, but I'm not counting on that.
		if ((home_set = xdg_config_home && strlen(xdg_config_home)) && sys_conf_dir)
		{
			_user_conf_path = new char[strlen(xdg_config_home) +
				strlen(sys_conf_dir) + DIRSEPLEN * 2 + 8];
			strcpy(_user_conf_path, xdg_config_home); start = strlen(xdg_config_home);
			strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
			strcpy(&_user_conf_path[start], ".config"); start += 7;
			strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
			strcpy(&_user_conf_path[start], sys_conf_dir);
		}
		else if (home_set)
		{
#ifdef PACKAGE_TARNAME
			_user_conf_path =
				new char[strlen(xdg_config_home) + strlen(PACKAGE_TARNAME) +
				DIRSEPLEN + 1];
			strcpy(_user_conf_path, xdg_config_home); start = strlen(xdg_config_home);
			strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
			strcpy(&_user_conf_path[start], PACKAGE_TARNAME);
#else
			_user_conf_path = new char[strlen(xdg_config_home)];
			strcpy(_user_conf_path, xdg_config_home);
#endif
		}
		// TODO: Export to separate function
		else if (sys_conf_dir)
		{
			_user_conf_path =
				new char[strlen(_cwd) + strlen(sys_conf_dir) + DIRSEPLEN + 1];
			strcpy(_user_conf_path, _cwd); start = strlen(_cwd);
			strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
			strcpy(&_user_conf_path[start], sys_conf_dir);
		}
		else
		{
#ifdef PACKAGE_TARNAME
			_user_conf_path =
				new char[strlen(_cwd) + strlen(PACKAGE_TARNAME) +
				DIRSEPLEN + 1];
			strcpy(_user_conf_path, _cwd); start = strlen(_cwd);
			strcpy(&_user_conf_path[start], DIRSEP); start += DIRSEPLEN;
			strcpy(&_user_conf_path[start], PACKAGE_TARNAME);
#else
			_user_conf_path = new char[strlen(_cwd)];
			strcpy(_user_conf_path, _cwd);
#endif
		}
	}

	// unix
#else

	// Beats me what to do, but I cannot fail here.
	if (sys_conf_dir)
	{
		_user_conf_path =
			new char[strlen(_cwd) + DIRSEPLEN + strlen(sys_conf_dir) + 1];
		strcpy(_user_conf_path, _cwd);
		strcpy(&_user_conf_path[strlen(_cwd)], DIRSEP);
		strcpy(&_user_conf_path[strlen(_cwd) + DIRSEPLEN], sys_conf_dir);
	}
	else
	{
		_user_conf_path = new char[strlen(_cwd) + 1];
		strcpy(_user_conf_path, _cwd);
	}

#endif

	if (create_or_die(_user_conf_path))
		_user_conf_path = _cwd;

	return _user_conf_path;
}

extern "C"
char* sys_getpath(int path)
{
	switch(path)
	{
		case GLOBAL_DATA_PATH:
			return get_gdata_path();
		case GLOBAL_CONFIG_PATH:
			return get_gconf_path();
		case USER_DATA_PATH:
			return get_udata_path();
		case USER_CONFIG_PATH:
			return get_uconf_path();
		default:
			return getcwd(NULL, 0);
	}
}

