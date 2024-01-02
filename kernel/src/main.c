#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>

#include <arch/cpu.h>
#include <requests.h>
#include <log.h>
#include <vendor/kprint.h>

LIMINE_BASE_REVISION(1)

void _start(void) {
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        arch_cpu_halt_cli();
    }

	serial_log_init();
	kprintf("Initializing kernel...\n");

    arch_cpu_halt();
}