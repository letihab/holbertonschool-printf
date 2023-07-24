#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
/**
 *struct set - function pair
 *@specifier: the format specification
 *@print: function implemented to print data of a given specifier stdout
 */
typedef struct Set
{
	char specifier;
	int (*print)(va_list arg);
} set;
int _printf(const char *format, ...);
int print_rev(va_list list);
int print_str(va_list list);
int print_char(va_list list);
int print_d(va_list list);
int print_rot13(va_list list);
int _putchar(char c);

#endif /* MAIN_H */