#include <limine.h>
#include <utils/kprint.h>
#include <arch/cpu.h>

LIMINE_BASE_REVISION(1);

void kernel_entry()
{
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
		kprintf("fatal: limine base revision not supported\n");
		arch_cpu_halt_cli();
	}

	serial_log_init();
	kprintf("This build has been compiled on %s at %s.\n", __DATE__, __TIME__);

    arch_cpu_halt();
}