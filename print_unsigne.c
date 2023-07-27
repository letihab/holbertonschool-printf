#include "main.h"
/**
 * print_unum - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unum(unsigned int n)
{
	int div = 1, len = 0;
	unsigned int num;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	while(div != 0)
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * unsigned_i - Prints Unsigned integers
 * @list: List of all of the argumets
 * Return: a count of the numbers
 */
int unsigned_i(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unum(num));

	if (num < 1)
		return (-1);
	return (print_unum(num));
}
