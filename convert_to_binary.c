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
 * convert_b - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int convert_b(va_list list)
{
	unsigned int num;
	int len, i;
	char *str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));

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
/**
 * convert_o - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int convert_o(va_list list)
{
	unsigned int num;
	int len;
	char *octal_rep;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_length(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;
	}

	octal_rep[len] = '\0';

	for (len = len - 1; len >= 0; len--)
		_putchar(octal_rep[len]);

	free(octal_rep);
	return (len);
}
