#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
/**
 *struct Set - function pair
 *@specifier: the format specification
 *@print: function implemented to print data of a given specifier stdout
 */
typedef struct Set
{
	char *specifier;
	int (*print)(va_list list);
} set;
int _printf(const char *format, ...);
int get_functions(const char *format, va_list list, set arguments[]);
int print_str(va_list list);
int print_char(va_list list);
int print_d(va_list list);
int _putchar(char c);
<<<<<<< HEAD
void my_printf(const char* format, ...);
=======
int convert_b(va_list list);
unsigned int base_length(unsigned int num, int base);
int convert_o(va_list list);
int convert_hex(va_list list);
int convert_HEX(va_list list);
int hex_check(int num, char x);
>>>>>>> feat/function_binaire

#endif /* MAIN_H */
