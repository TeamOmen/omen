#pragma once
#include <limine.h>

extern volatile struct limine_framebuffer_request framebuffer_request;
extern volatile struct limine_hhdm_request hhdm_request;
extern volatile struct limine_kernel_address_request kernel_addr_request;
extern volatile struct limine_memmap_request memmap_request;
extern volatile struct limine_rsdp_request rsdp_request;
extern volatile struct limine_smp_request smp_request;