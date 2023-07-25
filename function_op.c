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
	unsigned int m;
	int i = 0, k = 0, n = 0, count = 0;

	n = va_arg(list, int);
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n < 0)
		{
			n *= -1;
			_putchar('-');
			count += 1;
		}
		m = n;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;

		m = n;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			count++;
			k--;
			m = n;
		}
		_putchar(m % 10 + '0');
		count++;
	}
	else
	{
		return (-1);
	}

	return (count);
}
