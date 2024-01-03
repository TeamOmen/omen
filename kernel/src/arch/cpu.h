#pragma once
#include <stdint.h>

void arch_cpu_halt();
void arch_cpu_halt_cli();

void arch_outportb(uint16_t port, uint8_t data);
uint8_t arch_inportb(uint16_t port);