#include <limine.h>
#include <lib/kprint.h>
#include <arch/cpu.h>
#include <arch/init.h>

LIMINE_BASE_REVISION(1);

void kernel_entry()
{
    if(LIMINE_BASE_REVISION_SUPPORTED == false) {
		arch_cpu_halt_cli();
	}

	arch_init();

	kprintf("This build has been compiled on %s at %s.\n", __DATE__, __TIME__);

    arch_cpu_halt();
}