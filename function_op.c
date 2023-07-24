#include "main.h"
#include "_putchar.c"

/**
 * print_char - print a character
 * @list: args of va_list
 * Return: 1 if char, 0 if not
*/
int print_char(va_list list)
{
	char c;

	c = (va_arg(list, int));
	_putch(c);

	return (1);
}

/**
 * print_str - print a string
 * @list: list of args
 * Return: number of character in the string
*/
int print_str(va_list list)
{
	char *str;
	int i;

	str = (va_arg(list, char *));

	if (str == NULL)
		str = '(null)';

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}

/**
 * func_percent - print the sing percent
 * @list: the list of arguments the funcion id receiving
 * Return: 1 as just one of character
 */
int print_percent(__attribute__((unused)) va_list list)
{
	_putchar('%');
	return (1);
}
