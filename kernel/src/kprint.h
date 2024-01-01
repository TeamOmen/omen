#pragma once
#include <stdint.h>
#include <stdarg.h>

void putchar(char character);

/**
 * @brief Prints a formatted string. Takes varargs as values
 *
 * @param fmt Format string
 * @param ... Varargs
 * @return Count of characters written
 */
int kprintf(const char *fmt, ...);

/**
 * @brief Prints a formatted string. Takes a vararg list as values
 *
 * @param fmt Format string
 * @param list Vararg list
 * @return Count of characters written
 */
int kprintv(const char *format, va_list list);

/**
 * Initializes serial log
*/
void serial_log_init(void);