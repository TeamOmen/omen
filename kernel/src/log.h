#pragma once
#include <stdint.h>
#include <vendor/kprint.h>

void serial_log_init(void);
void serial_log(char *fmt, ...);