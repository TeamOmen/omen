#include <arch/init.h>
#include <arch/x86_64/serial.h>

void arch_init()
{
    x86_64_serial_init();
}

void kprint_sink(char ch)
{
	x86_64_serial_char(ch);
}