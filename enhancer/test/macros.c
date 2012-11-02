#include <stdio.h>
#include "../system/paths.h"
#include "../system/osdetect.h"

int main(int argc, char** argv)
{
	int err = 0;
	fprintf(stderr, "Macro path request tests\n");
	fprintf(stderr, "\tData dir: %s\n", sys_getpath(DATA_PATH));
	return err;
}

