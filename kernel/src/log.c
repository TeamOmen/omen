#include "log.h"
#include <stdarg.h>
#include <arch/cpu.h>

#define COM1 0x3F8

#define MOD_ACTIVE (1 << 0)
#define MOD_LONG (1 << 1)
#define MOD_PREFIX (1 << 2)

static const char *g_num_chars = "0123456789ABCDEF";

void putchar(char ch) {
    outportb(COM1, ch);
}

static void serial_log_out_num(uint64_t value, uint64_t radix) {
    uint64_t pw = 1;
    while(value / pw >= radix) pw *= radix;

    while(pw > 0) {
        uint8_t c = value / pw;
        putchar(g_num_chars[c]);
        value %= pw;
        pw /= radix;
    }
}

void serial_log_init(void) {
	/* Enable DLAB (Divisor Latch Access Bit) */
	outportb(COM1 + 3, 0x80);

	/* Set divisor low byte (115200 baud) */
	outportb(COM1 + 0, 0x03);

	/* Set divisor high byte */
	outportb(COM1 + 1, 0x00);

	/* Set parity */
	outportb(COM1 + 3, 0x03);

	/* Enable FIFO, clear transmit and receive FIFO queues */
    outportb(COM1 + 2, 0xC7);

	/* Clear them */
    outportb(COM1 + 4, 0x0B);

	/* Enable interrupts */
	outportb(COM1 + 1, 0x01);
}