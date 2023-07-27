#include "main.h"

/**
 * rev_s - print a string in reverse
 * @arg: parameter to print
 * Return: number of printed characters
 */
int rev_s(va_list arg)
{
	int length = 0, i, nb_char = 0;

	char *s = va_arg(arg, char *);

	while (s[length] != '\0')
		length++;

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
		nb_char++;
	}

	return (nb_char);
}

/**
 * ROT13 - print a string encoded using rot13
 * @arg: string passe in arg
 * Return: number of printed char
 */
int ROT13(va_list arg)
{
	int i, j, nb_char = 0;
	char array1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char array2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arg, char *);

	for (i = 0; str[i]; i++, nb_char++)
	{
		for (j = 0; array1[j]; j++)
		{
			if (str[i] == array1[j])
			{
				_putchar(array2[j]);
				break;
			}
		}
		if (str[i] != array1[j])
			_putchar(str[i]);
	}

	return (nb_char);
}
