#ifndef _ENHANCER_UTF8
#define _ENHANCER_UTF8
/**\addtogroup enh-mbc
 * @{
 * \~English \file
 * UTF-8 character codes to integer conversion algorithms.
 * This file holds definition to functions that examines given UTF-8 characters
 * stored byte-length or convert them to positive integer values or back to
 * UTF-8 characters.
 * \par
 * \todo Document usage recomendation.
 */

#ifdef __cplusplus__
#include <cstdlib>
extern "C" {
#else
#include <stdlib.h>
#endif

// This will be in a separate multi byte handler file, if I ever write it.
//int mbtoi(const char* ch);

/**\~English
 * UTF-8 encoded multi-byte to integer converter.
 * This function will convert a string, that contains only one valid UTF-8
 * character to it's UNICODE code value as a positive integer.
 *
 * \param[in]  ch The string containing the UTF-8 encoded character.
 *
 * \returns A positive integer value, that is the UNICODE code point for that
 * character.
 *
 * \note This function does not check for any other validity of the character
 * other than the string only contains one and complete UNICODE character
 * according to it's header byte. Like it would also decode for example \c { \c
 * 0xc0, \c 0x8a \c } as \c 10 , but it should been coded as \c 0x0a .
 */
int utf8toi(const char* ch);

/**\~English
 * Expands the byte-length from a multi-byte UTF-8 encoded character's header
 * byte.
 * This function will retrieve the length information of the header byte
 * given as the argument.
 *
 * \param[in]  ch The header byte of a valid UTF-8 character.
 *
 * \returns A non-negative integer value, that represent the number of bytes the
 * UTF-8 character made of.
 *
 * \note This function will return 1 even if it is a trailer character, and not
 * a header character.
 *
 * \note This functions range is up to 8 but the highest possible value defined
 * by UTF-8 standard is 6.
 */
int cutf8len(const char ch);

/**\~English
 * Expands the byte-length from a multi-byte UTF-8 encoded character.
 * This function will retrieve the length information of the UTF-8 character
 * given as the argument.
 *
 * \param[in]  ch The UTF-8 character as a string
 *
 * \returns A non-negative integer value representing the number of bytes, that
 * the given UTF-8 character made of, or 0 if it does not denotes one full UTF-8
 * character.
 *
 * \note The function will assume that the string contains only one valid UTF-8
 * character. If it obviously does not, then it will return 0.
 *
 * \note This functions range is up to 8 but the highest possible value defined
 * by UTF-8 standard is 6.
 */
int sutf8len(const char* ch);

/**\~English
 * Computes the required bytes for UNICODE code point.
 * The function will calculate the required number of bytes to store the
 * supplied integer, interpreted as a UNICODE code point.
 *
 * \param[in]  i The integer to be coded as a UNICODE code point.
 *
 * \returns A non-negative number, representing the number of bytes to store the
 * supplied integer, or 0 if it is out of the UNICODE code point range.
 */
int iutf8len(unsigned int i);

/**\~English
 * Convert an integer to UTF-8 character.
 * This function will convert the supplied integer in to the supplied \c ch
 * string buffer that is of \c len sized.
 *
 * \param[in]  i   The integer to be converted to UTF-8 character.
 * \param[out] ch  The string buffer to convert it into.
 * \param[in]  len The length of the string buffer that is supplied.
 *
 * \returns The created string that contains only one UTF-8 character, that is
 * also stored \c ch if not \c NULL was supplied.
 *
 * \warning This function was not written as the developer intented to, and may
 * not behave in the desired manner.
 */
char* itoutf8(const int i, char** ch, size_t len);

/// @}

#ifdef __cplusplus__
}
#endif

#endif

