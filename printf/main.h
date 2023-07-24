#ifndef our_printf
#define our_printf
#include <stdio.h>
#include <stdarg.h>

/**
 *struct set - function pair
 *@specifie: the format specification
 *@print: function implemented to print data of a given specifier stdout
 */
typedef struct Set
{
	char specifie;
	int (*print)(va_list arg);
} set;
int _printf(const char *format, ...);//produces output according to a format
int print_rev(va_list list);// print string in reverse
int print_str(va_list list);//print string
int print_char(va_list list); // print char
int print_d(va_list list); //print integer
int print_rot13(va_list list); //encode a string using rot 13 and print it to stdout
int _putchar(char c);

#endif
