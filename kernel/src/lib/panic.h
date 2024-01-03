#pragma once
#include <lib/kprint.h>
#include <arch/cpu.h>

static inline void panic(char *reason) {
    kprintf("kernel panic: %s\n", reason);
    arch_cpu_hang();
}
