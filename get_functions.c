#include "main.h"

/**
 * get_functions - match format with function format
 * @format: It's a character string
 * @list: the list of arguments the function _printf is receiving
 * @arguments: structure of arguments use to compare
 * Return: the number of character the function is printing
 */
int get_functions(const char *format, va_list list, set arguments[])
{
	int i = 0, j = 0, count = 0;

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			count += _putchar(format[i]);
		else
		{
			for (j = 0; arguments[j].specifier; j++)
			{
				if (format[i + 1] == arguments[j].specifier[0])
				{
					count += arguments[j].print(list);
					i++;
					break;
				}
			}
			if (arguments[j].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '%')
				{
					count += _putchar(format[i]);
					count += _putchar(format[i + 1]);
					i++;
				}
				else
				{
					count += _putchar(format[i + 1]);
					i++;
				}
			}
		}
	}
	va_end(list);
	return (count);
}
