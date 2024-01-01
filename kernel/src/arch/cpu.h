#pragma once

#include <utils/def.h>

void arch_cpu_halt();
void arch_cpu_halt_cli();

void outportb(uint16_t port, uint8_t data);
uint8_t inportb(uint16_t port);