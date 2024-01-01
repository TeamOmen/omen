#pragma once

#define KIB 1024ULL
#define MIB (KIB * 1024ULL)
#define GIB (MIB * 1024ULL)

#define PAGE_SIZE 0x1000 // 4 KiB

#define HHDM (hhdm_request.response->offset)