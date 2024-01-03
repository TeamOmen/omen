#include "cpu.h"
#include <arch/cpu.h>

[[noreturn]] void arch_cpu_hang()
{
	asm volatile("cli");
	for(;;) asm volatile("hlt");
	__builtin_unreachable();
}

uint8_t x86_64_inportb(uint16_t port)
{
	unsigned char rv;
	asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (port));
	return rv;
}

void x86_64_outportb(uint16_t port, uint8_t data)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (data));
}