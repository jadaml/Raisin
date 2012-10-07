#include <string.h>
#include <stdio.h>
#include "../algo/utf8.h"

int main(int argc, char** argv)
{
	int start = 0, end = 128;
	if (argc > 1) start = atoi(argv[1]);
	if (argc > 2) end = atoi(argv[2]);
	for (int i = start; i < 0x7FFFFFFF && i < end; ++i)
	{
		int mbclen = iutf8len(i);
		char* ch = itoutf8(i, NULL, 0);
		printf("%08x ", i);
		for (int j = 0; j < mbclen; ++j)
		{
			printf("%02x ", ch[j]);
		}
		if (i < 0x20)
			printf("^%c\n", i + 0x40);
		else if (i == 0x7F)
			printf("^%c\n", i - 0x40);
		else
			printf("%s\n", ch);
	}

	// A test that I did not made:
	char* mbc = "ő";
	itoutf8(0x151, mbc, 2);
	if (strcmp(mbc, "ő") != 0) puts("You should double check you're implementation");
	return 0;
}

