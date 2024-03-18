/* 	util.c - contains utlities used by sim (not arch) */
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

char decimal_to_hex(uint8_t i) {
	switch(i) {
		case 0:
		    return '0';
		    break;
		case 1:
		    return '1';
		    break;
		case 2:
		    return '2';
		    break;
		case 3:
		    return '3';
		    break;
		case 4:
		    return '4';
		    break;
		case 5:
		    return '5';
		    break;
		case 6:
		    return '6';
		    break;
		case 7:
		    return '7';
		    break;
		case 8:
		    return '8';
		    break;
		case 9:
		    return '9';
		    break;
		case 10:
		    return 'A';
		    break;
		case 11:
			return 'B';
			break;
		case 12:
			return 'C';
			break;
		case 13:
			return 'D';
			break;
		case 14:
			return 'E';
			break;
		case 15:
			return 'F';
			break;
		default:
			return '\0';
			break;
	}
}

bit_8 str_to_bit_8(string str) {
	bit_8 			result;
	uint8_t 		i,
					j,
					accumulator;

	accumulator 	= 1 << 7,
	result 			= 0,
	i				= 0,
	j				= 0;

	while (str[i] != '\0' || j <= 7) {
		/* 	just like verilog, let's have neatly formatted bit representations */
		if (str[i] == '_')
			i++;
		if (str[i] == '1') {
			result += accumulator;
			j++;
		} else {
			j++;
		}
		i++;
		accumulator = accumulator >> 1;
	}
	return result;
}

struct bit_16 str_to_bit_16(string str) {
	struct bit_16 	result;
	uint8_t 		i,
					j,
					accumulator;

	accumulator 	= 1 << 7,
	result.upper	= 0,
	result.lower	= 0,
	i				= 0,
	j				= 0;

	while (str[i] != '\0' || j <= 15) {
		/* 	just like verilog, let's have neatly formatted bit representations */
		if (str[i] == '_')
			i++;
		if (str[i] == '1') {
			if (j <= 7)
				result.upper += accumulator;
			else
				result.lower += accumulator;
			j++;
		} else {
			j++;
		}
		i++;
		accumulator = accumulator >> 1;
		if (accumulator == 0) accumulator = 1 << 7;
	}
	return result;
} 

int bit_8_to_decimal(bit_8 b) {
	return (int) b;
}

int bit_16_to_decimal(struct bit_16 b) {
	return (b.upper << 8) + b.lower;
}

string bit_8_to_hex(bit_8 b, char* out) {
	char 		upper, 
		 		lower;	
	char*		new_str;

	upper 		= decimal_to_hex((uint8_t) (b >> 4));
	lower		= decimal_to_hex((uint8_t) (b & 15));

	if (out != 0) {
		out[0] = '0';
		out[1] = 'x';
		out[2] = upper;
		out[3] = lower;
		out[4] = '\0';
		return (string) out;
	}
	else {
		new_str = malloc(5);
		new_str[0] = '0';
		new_str[1] = 'x';
		new_str[2] = upper;
		new_str[3] = lower;
		new_str[4] = '\0';
		return (string) new_str;
	}
}

string bit_16_to_hex(struct bit_16 b, char* out) {
	char 		first, 
		 		second,
				third,
				fourth;	
	char*		new_str;

	first 		= decimal_to_hex((uint8_t) (b.upper >> 4));
	second		= decimal_to_hex((uint8_t) (b.upper & 15));
	third 		= decimal_to_hex((uint8_t) (b.lower >> 4));
	fourth		= decimal_to_hex((uint8_t) (b.lower & 15));

	if (out != 0) {
		out[0] = '0';
		out[1] = 'x';
		out[2] = first;
		out[3] = second;
		out[4] = third;
		out[5] = fourth;
		out[6] = '\0';
		return (string) out;
	}
	else {
		new_str = malloc(7);
		new_str[0] = '0';
		new_str[1] = 'x';
		new_str[2] = first;
		new_str[3] = second;
		new_str[4] = third;
		new_str[5] = fourth;
		new_str[6] = '\0';
		return (string) new_str;
	}
}

void set_bit_8_bit(bit_8* b, uint8_t bit) {
	*b = *b | (1 << bit);
}

void clear_bit_8_bit(bit_8* b, uint8_t bit) {
	*b = *b & ~(1 << bit);
}

void set_bit_16_bit(struct bit_16* b, uint8_t bit) {
	if (bit > 7) b->upper = b->upper | (1 << (bit - 8));
	else b->lower = b->lower | (1 << bit);
}

void clear_bit_16_bit(struct bit_16* b, uint8_t bit) {
	if (bit > 7) b->upper = b->upper & ~(1 << (bit - 8));
	else b->lower = b->lower & ~(1 << bit);
}
