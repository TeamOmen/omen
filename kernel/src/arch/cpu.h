#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void arch_cpu_halt(void);
void arch_cpu_halt_cli(void);

void outportb(uint16_t _port, uint8_t data);
uint8_t inportb(uint16_t _port);