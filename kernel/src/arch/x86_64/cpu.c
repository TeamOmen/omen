#include <stdint.h>
#include <arch/cpu.h>

void arch_cpu_halt(void) {
	asm ("1: hlt; jmp 1");
}

void arch_cpu_halt_cli(void) {
	asm ("cli; 1: hlt; jmp 1");
}

uint8_t inportb(uint16_t _port) {
	unsigned char rv;
	asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

void outportb(uint16_t _port, uint8_t _data) {
	asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}