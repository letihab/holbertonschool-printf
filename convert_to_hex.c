#include "main.h"

/**
 * convert_hex - Prints a representation of a decimal number on base16 lower
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int convert_hex(va_list list)

{
	unsigned int num;
	int len, rem_num;
	char *hex_rep;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_length(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';

	for (len = len - 1; len >= 0; len--)
		_putchar(hex_rep[len]);

	free(hex_rep);

	return (len);
}


/**
 * convert_HEX - Prints a representation of a decimal number on base16 Upper
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int convert_HEX(va_list list)
{
	unsigned int num;
	int len, rem_num;
	char *hex_rep;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);

	len = base_length(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);

	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';

	for (len = len - 1; len >= 0; len--)
		_putchar(hex_rep[len]);

	free(hex_rep);

	return (len);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
