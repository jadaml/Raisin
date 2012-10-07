#ifndef _ENHANCER_UTF8
#define _ENHANCER_UTF8

#ifdef __cplusplus__
#include <cstdlib>
extern "C" {
#else
#include <stdlib.h>
#endif

// This will be in a separate multi byte handler file, if I ever write it.
//int mbtoi(const char* ch);

int utf8toi(const char* ch);

int cutf8len(/*const char* ch*/);

int iutf8len(unsigned int i);

char* itoutf8(const int i, char* ch, size_t len);

#ifdef __cplusplus__
}
#endif

#endif

