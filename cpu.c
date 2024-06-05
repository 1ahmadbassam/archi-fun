/* 	cpu.c - primary computational model */
#include "cpu.h"
#include "util.h"

struct cpu_mod cpu;

int cpu_reset(void) {
	/* reset processor registers */
	cpu.regs.working = bit_16_z;
	cpu.regs.general = bit_16_z;
	cpu.regs.status = bit_16_z;
	set_bit_16_bit(&cpu.regs.status, 15);
	return 0;
}

int exec(void) {
	bit_8 		instr;
	uint8_t		op;

	while(bit_16_bit(&cpu.regs.status, 15)) {
		if (bit_16_bit(&cpu.regs.status, 14)) {
			instr = cpu.regs.status.lower;
			op = (uint8_t) instr >> 5;
			if (op == str_to_bit_8("0000_0111")) break;
		}
	}
	return 0;
}
