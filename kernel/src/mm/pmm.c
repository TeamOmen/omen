#include "pmm.h"
#include <mm/hhdm.h>
#include <stddef.h>
#include <lib/kprint.h>
#include <lib/round.h>
#include <lib/panic.h>
#include <arch/types.h>

typedef struct pmm_region {
    uintptr_t base_address;
    unsigned int page_count;
    struct pmm_region *next;
    pmm_page_t pages[];
} pmm_region_t;

static_assert(sizeof(pmm_region_t) + sizeof(pmm_page_t) < ARCH_PAGE_SIZE); // pmm_init relies on this assumption

static pmm_region_t *g_regions;
static pmm_page_t *g_freelist;

/** @warning Relies on identity map */
void pmm_init(struct limine_memmap_entry **map, uint64_t map_length) {
    g_freelist = NULL;
    g_regions = NULL;

    kprintf("Memory map\n");
    for(uint64_t i = 0; i < map_length; i++) {
        struct limine_memmap_entry *entry = map[i];
        kprintf("> %lu | %#lx, %#lx\n", entry->type, entry->base, entry->length);

        if(entry->type != LIMINE_MEMMAP_USABLE) continue;
        pmm_region_t *region = (pmm_region_t *) HHDM(entry->base);
        region->base_address = entry->base;
        region->page_count = entry->length / ARCH_PAGE_SIZE;
        region->next = g_regions;
        g_regions = region;

        unsigned int reserved_pages = ROUND_DIV_UP(sizeof(pmm_region_t) + region->page_count * sizeof(pmm_page_t), ARCH_PAGE_SIZE);

        for(unsigned int j = 0; j < region->page_count; j++) {
            region->pages[j].address = region->base_address + j * ARCH_PAGE_SIZE;
            region->pages[j].free = false;
            region->pages[j].next = NULL;
        }
        for(unsigned int j = reserved_pages; j < region->page_count; j++) {
            pmm_free(&region->pages[j]);
        }
    }
}

pmm_page_t *pmm_alloc() {
    pmm_page_t *page = g_freelist;
    if(page == NULL) panic(__FILE__ ": OOM");
    g_freelist = page->next;
    page->free = false;
    return page;
}

void pmm_free(pmm_page_t *page) {
    page->free = true;
    page->next = g_freelist;
    g_freelist = page;
}