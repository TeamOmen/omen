#include "serial.h"
#include <arch/x86_64/cpu.h>

#define COM1 0x3F8

#define MOD_ACTIVE (1 << 0)
#define MOD_LONG (1 << 1)
#define MOD_PREFIX (1 << 2)

void x86_64_serial_init()
{
    /* Enable DLAB (Divisor Latch Access Bit) */
	x86_64_outportb(COM1 + 3, 0x80);

	/* Set divisor low byte (115200 baud) */
	x86_64_outportb(COM1 + 0, 0x03);

	/* Set divisor high byte */
	x86_64_outportb(COM1 + 1, 0x00);

	/* Set parity */
	x86_64_outportb(COM1 + 3, 0x03);

	/* Enable FIFO, clear transmit and receive FIFO queues */
    x86_64_outportb(COM1 + 2, 0xC7);

	/* Clear them */
    x86_64_outportb(COM1 + 4, 0x0B);

	/* Enable interrupts */
	x86_64_outportb(COM1 + 1, 0x01);

}

void x86_64_serial_char(char ch)
{
    x86_64_outportb(COM1, ch);
}