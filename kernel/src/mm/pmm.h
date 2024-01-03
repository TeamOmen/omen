#pragma once
#include <limine.h>

typedef struct pmm_page {
    uintptr_t address;
    bool free;
    struct pmm_page *next;
} pmm_page_t;

void pmm_init(struct limine_memmap_entry **map, uint64_t map_length);

pmm_page_t *pmm_alloc();
void pmm_free(pmm_page_t *page);