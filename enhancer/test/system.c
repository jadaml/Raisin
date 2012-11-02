#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../system/osdetect.h"
#include "../system/paths.h"

int main(int argc, char** argv)
{
//	int j;
	int i, err = 0;
	char* cwd1 = NULL;
//	char* cwd2 = NULL;
	char* tmp = NULL;

//	fprintf(stderr, "Os detection test ... ");

	i = sys_platform();
//#ifdef _WIN32
//	j = PLATFORM_WINDOWS;
//#elif defined __APPLE__
//	j = PLATFORM_APPLE;
//#elif defined unix
//	j = PLATFORM_UNIX;
//#else
//	j = PLATFORM_UNKNOWN;
//#endif

//	fprintf(stderr, "OS detected is %d - it should be %d\n", i, j);
	fprintf(stderr, "OS detected is %d\n", i);

//	if (i != j)
//	{
//		printf("OS detection failed - New os addition made?\n");
//		err = 1;
//	}
//	else
//		fprintf(stderr, "PASS\n");

	fprintf(stderr, "Path request tests\n");

//#ifdef unix
//#if defined PREFIX && defined PACKAGE_NAME
//	// TODO
//#else
//	tmp = getcwd(NULL, 0);
//	cwd2 = calloc(strlen(tmp) + strlen(DIRSEP) + 5, sizeof(char));
//	strcpy(cwd2, getcwd(NULL, 0));
//	strcpy(&(cwd2[strlen(tmp)]), DIRSEP);
//	strcpy(&(cwd2[strlen(tmp) + strlen(DIRSEP)]), "data");
//#endif
//#endif

//	fprintf(stderr, "Got %s Should be %s\n", cwd1 = sys_getpath(DATA_PATH), cwd2);
//
	fprintf(stderr, "\tProgram data path: %s\n", sys_getpath(DATA_PATH));

//	if (strcmp(cwd1, cwd2) != 0)
//	{
//		fprintf(stderr, "\nWrong data path - Where did it came from?\n");
//		err = 1;
//	}
//	else
//		fprintf(stderr, "PASS\n");

	return err;
}

