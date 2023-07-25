#include "main.h"

/**
 * print_char - print a character
 * @list: args of va_list
 * Return: 1 if char, 0 if not
*/
int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);
	_putchar(c);

	return (1);
}

/**
 * print_str - print a string
 * @list: list of args
 * Return: number of character in the string
*/
int print_str(va_list list)
{
	const char *str;
	int count = 0;

	str = va_arg(list, const char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * print_d - print a decimal number
 * @list: list of argument taken
 * Return: Number
*/
int print_d(va_list list)
{
	int m, k, n;
	int count = 0;

	n = va_arg(list, int);

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
		m = n;
		for (k = 1; m >= 10; k *= 10)
			m /= 10;

		while (k > 0)
		{
			_putchar((n / k) + '0');
			count++;
			n %= k;
			k /= 10;
		}
	return (count);
}
