#include <string.h>
#include "utf8.h"

int utf8toi(const char* ch)
{
	int chlen = strlen(ch);
	if (chlen <= 0)
		return 0;
	if (chlen == 1) return (int) ch[0];
	else
	{
		int retval = 0;
		for (int i = 0; i < chlen; ++i)
		{
			char head = 0;
			retval <<= 6;
			if (i == 0)
			// Header character
			{
				head = 0xFF << (7 - chlen);
				retval = ch[i] & ~head;
			}
			else
			// Trailer character
			{
				head = 0xC0;
				retval += ch[i] & ~head;
			}
		}
		return retval;
	}
}

int cutf8len(/* const char* ch */)
{
	// TODO
	return -1;
}

/* Shift guide
 * ......80  .... .... .... .... .... .... *... .... 
 * .....800  .... .... .... .... .... *... .... .... 
 * ...10000  .... .... .... ...* .... .... .... .... 
 * ..200000  .... .... ..*. .... .... .... .... .... 
 * .4000000  .... .*.. .... .... .... .... .... .... 
 * 80000000  *... .... .... .... .... .... .... .... 
 */

int iutf8len(unsigned int i)
{
	int j = 0;
	if (i >= 0x80000000) return 0;
	else if (i < 0x80) return 1;
	else
	{
		unsigned int limit = 0x800;
		// This won't run forever, because the first if guarantees that for us.
		for (j = 2; i >= limit; ++j)
			limit <<= 5;
	}
	return j;
}

char* itoutf8(const int i, char* ch, size_t len)
{
	char* retval;
	size_t chlen = iutf8len((unsigned int)i);
	// Can't work with these arguments.
	if (chlen == 0)
	{
		if (ch != NULL && len > 0)
			ch[0] = '\0';
		return NULL;
	}
	if (ch != NULL && chlen > len) return NULL;
	if (ch != NULL) retval = ch;
	// BUG: Segfaults if ch != NULL
	else retval = calloc(chlen + 1, sizeof(char));
	// It might become more clear, if we go from chlen - 1 to 0 instead.
	for (int j = 0; (size_t)j < chlen; ++j)
	{
		if (j == 0)
		{
			char mask = 0x7F >> (chlen - 1);
			retval[j] = ((chlen > 1)?0xFE << (7 - chlen):0)
				| ((i & 0x3F << ((chlen - 1) * 6)) >> ((chlen - 1) * 6)
				& mask);
		}
		else
			retval[j] = 0x80 | (i & 0x3F << ((chlen - j - 1) * 6))
				>> ((chlen - j - 1) * 6);
	}
	retval[chlen] = '\0';
	return retval;
}

