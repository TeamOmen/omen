#include <limine.h>
#include <utils/def.h>

#include <arch/cpu.h>

#include <utils/def.h>
#include <utils/kprint.h>

LIMINE_BASE_REVISION(1)

void kernel_entry()
{
    if (LIMINE_BASE_REVISION_SUPPORTED == false)
        arch_cpu_halt_cli();

	serial_log_init();
	kprintf("This build has been compiled on %s at %s.", __DATE__, __TIME__);

    arch_cpu_halt();
}