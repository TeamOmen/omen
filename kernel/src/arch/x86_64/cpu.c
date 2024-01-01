#include <arch/cpu.h>

void arch_cpu_halt()
{
	asm ("1: hlt; jmp 1");
}

void arch_cpu_halt_cli()
{
	asm ("cli; 1: hlt; jmp 1");
}

uint8_t inportb(uint16_t port)
{
	unsigned char rv;
	asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (port));
	return rv;
}

void outportb(uint16_t port, uint8_t data)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (data));
}