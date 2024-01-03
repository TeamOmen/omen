#pragma once
#include <stdint.h>

void x86_64_outportb(uint16_t port, uint8_t data);
uint8_t x86_64_inportb(uint16_t port);