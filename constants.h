/* 	constants.h - defines architechtural constants */
#ifndef CONSTANTS_HEADER
#define CONSTANTS_HEADER

#define BIT_SIZE 16

typedef unsigned char bit_8;
typedef unsigned char uint8_t;

struct bit_16 {
	bit_8 upper;
	bit_8 lower;
};

extern struct bit_16 bit_16_z = {0, 0};

#endif
