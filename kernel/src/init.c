#include <limine.h>
#include <request.h>
#include <lib/kprint.h>
#include <mm/pmm.h>
#include <arch/cpu.h>
#include <arch/init.h>

LIMINE_BASE_REVISION(1);

void kernel_entry()
{
    if(LIMINE_BASE_REVISION_SUPPORTED == false) {
		arch_cpu_hang();
	}

	arch_init();

	pmm_init(request_memmap.response->entries, request_memmap.response->entry_count);

	kprintf("This build has been compiled on %s at %s.\n", __DATE__, __TIME__);

    arch_cpu_hang();
}