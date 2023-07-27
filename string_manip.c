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

	for (i = length; i >= 0; i--)
	{
		_putchar(s[i]);
		nb_char++;
	}

	return (nb_char);
}

/**
 * ROT13 - print a string encoded using rot13
 * @flag: Flag parameters
 * Return: number of printed char
 */
int ROT13(va_list arg)
{
	int i, j, nb_char = 0;
	char ch1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ch2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arg, char *);

	for (i = 0; str[i]; i++, nb_char++)
	{
		for (j = 0; ch1[j]; j++)
		{
			if (str[i] == ch1[j])
			{
				_putchar(ch2[j]);
				break;
			}
		}
		if (str[i] != ch1[j])
			_putchar(str[i]);
	}

	return (nb_char);
}
