#pragma once
#include <stdint.h>
#include <request.h>

#define HHDM_TO(ADDR) ((uintptr_t) (ADDR) + request_hhdm.response->offset)
#define HHDM_FROM(ADDR) ((uintptr_t) (ADDR) - request_hhdm.response->offset)
#define HHDM(ADDR) HHDM_TO(ADDR)