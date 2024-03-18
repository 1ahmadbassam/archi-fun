/* util.h - contains utlities used by sim (not arch) - header file */
#ifndef UTIL_HEADER
#define UTIL_HEADER

#include "constants.h"

typedef const char* string;

/* general utility functions */
char decimal_to_hex(uint8_t i);

/* bit - manip operations */

/* 	convert an input string to an 8-bit number
	assumes that the string is properly formatted */
extern bit_8 str_to_bit_8(string str);

/* 	convert an input string to a 16-bit number
	assumes that the string is properly formatted */
extern struct bit_16 str_to_bit_16(string str);

/* 	convert an input bit_8 to decimal */
extern int bit_8_to_decimal(bit_8 b);

/* 	convert an input bit_16 to decimal */
extern int bit_16_to_decimal(struct bit_16 b);

/* 	convert an input bit_8 to hex, 
	storing output into out if out is not null
	assumes that output is exactly 5 characters wide ("0xff\0")
	if out is null, then creates a new string (using malloc) and returns that
	else returns out */
extern string bit_8_to_hex(bit_8 b, char* out);

/* 	convert an input bit_16 to hex, 
	storing output into out if out is not null
	assumes that output is exactly 7 characters wide ("0xffff\0")
	if out is null, then creates a new string (using malloc) and returns that
	else returns out */
extern string bit_16_to_hex(struct bit_16 b, char* out);

#endif
