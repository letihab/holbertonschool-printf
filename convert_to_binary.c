#include "main.h"

/**
 * base_len - Calculates the length for a number
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 * Return: An integer representing the length of a number
 */
unsigned int base_length(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
		num /= base;

	return (i);
}

/**
 * write_string - write a standard string
 * @str: string
*/
void write_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
/**
 * print_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list list)
{
	unsigned int num;
	int len, i;
	char *str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return(_putchar('0'));

	if (num < 1)
		return (-1);

	len = base_length(num, 2);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';

		num /= 2;
	}
	str[i] = '\0';

	for (i = i - 1; i >= 0; i--)
		_putchar(str[i]);

	free(str);

	return (len);
}
