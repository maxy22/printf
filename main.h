#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <limits.h>

int _printf(const char *format, ...);

int print_number(int n, int base, int signed_);

int print_hex(unsigned int n, int uppercase);

int print_pointer(void *ptr);

#endif /* MAIN_H */ 

