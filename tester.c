/*	tester.c - tests functions and methods for correctness */

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

void test_util_bin() {
	string sample1 = "10101010";
	bit_8 sample1_res = str_to_bit_8(sample1);
	printf("%d\n", sample1_res);
	string sample2 = "1010_0010_0101_1101";
	struct bit_16 sample2_res = str_to_bit_16(sample2);
	printf("%d_%d\n", sample2_res.upper, sample2_res.lower);
	printf("%d\n", bit_8_to_decimal(sample1_res));
	printf("%d\n", bit_16_to_decimal(sample2_res));

	string sample1_hex = bit_8_to_hex(sample1_res, 0);
	printf(sample1_hex);
	printf("\n");
	free((void *) sample1_hex);
	char* sample1_hex_mut = malloc(5);
	bit_8_to_hex(sample1_res, sample1_hex_mut);
	printf(sample1_hex_mut);
	printf("\n");
	free((void *) sample1_hex_mut);

	string sample2_hex = bit_16_to_hex(sample2_res, 0);
	printf(sample2_hex);
	printf("\n");
	free((void *) sample2_hex);
	char* sample2_hex_mut = malloc(7);
	bit_16_to_hex(sample2_res, sample2_hex_mut);
	printf(sample2_hex_mut);
	printf("\n");
	free((void *) sample2_hex_mut);

}

void test_cpu() {
	printf("reset %d\n", cpu_reset());
	printf("%d\n", bit_16_to_decimal(cpu.regs.status));
}

int main() {
	test_cpu();
	return 0;
}
