/* 	cpu.h - primary computational model - header file */
#ifndef CPU_HEADER
#define CPU_HEADER

#include "constants.h"

/* 	currently, the architechture consists of four 16-bit registers
	a working register "working"
	a status register "status"
	and a general purpose register "general" */

struct cpu_regs {
	struct bit_16 working;
	/* right now, only the MSB of this register means something,
	and it means that the processor is functional if asserted */
	struct bit_16 status;
	struct bit_16 general; 
};

struct cpu_mod {
	struct cpu_regs regs;
};

/* processor model - C-struct with all processor components */
extern struct cpu_mod cpu;

/* on init, or on reset, reset processor state */
extern int cpu_reset(void);

/* perform computation until stop */
extern int exec(void);

#endif
