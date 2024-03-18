/* 	cpu.c - primary computational model */
#include "cpu.h"

struct cpu_mod cpu;

int cpu_reset(void) {
	/* reset processor registers */
	cpu.regs.working = bit_16_z;
	cpu.regs.general = bit_16_z;
	cpu.regs.status = bit_16_z;
	set_bit_16_bit(&cpu.regs.status, 15);
	return 0;
}
