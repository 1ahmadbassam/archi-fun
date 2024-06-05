/* 	util.h - contains utlities used by sim (not arch) - header file */
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
extern uint8_t bit_8_to_decimal(bit_8 b);

/* 	convert an input bit_16 to decimal */
extern int bit_16_to_decimal(struct bit_16* b);

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
extern string bit_16_to_hex(struct bit_16* b, char* out);

/* TODO: 
	
extern bit_8 hexstr_to_bit_8(string str);
extern struct bit_16 hexstr_to_bit_16(string str);

*/

/*	sets a bit of a specified bit_8 */
extern void set_bit_8_bit(bit_8* b, uint8_t bit);

/*	clears a bit of a specified bit_8 */
extern void clear_bit_8_bit(bit_8* b, uint8_t bit);

/*	sets a bit of a specified bit_8 */
extern void set_bit_16_bit(struct bit_16* b, uint8_t bit);

/*	clears a bit of a specified bit_8 */
extern void clear_bit_16_bit(struct bit_16* b, uint8_t bit);

/* 	get bit of a specified bit_8 */
extern uint8_t bit_8_bit(bit_8 b, uint8_t bit);

/* 	get bit of a specified bit_16 */
extern uint8_t bit_16_bit(struct bit_16* b, uint8_t bit);

#endif
