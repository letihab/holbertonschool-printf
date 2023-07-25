#include "main.h"

/**
 *_printf - function that produces output according to a format
 *@format: parameter to specifie a type of entry
 *Return:the number of the characters printed
 */
int _printf(const char *format, ...)
{
	int i, j, count;
	va_list list;
	set arguments[] = {
		{'c', print_char},
		{'d', print_d},
		{'i', print_d},
		{'s', print_str},
		/**{'R', print_rot13},
		{'r', print_rev},*/
	};

	if (format == NULL)
		return (-1);

	va_start(list, format);

	count = 0;

	for (i = 0; format && *(format + i) != '\0'; i++)
	{
		if (format[i] != '%')
			count += _putchar(format[i]);
		else
		{
			for (j = 0; arguments[j].specifier; j++)
			{
				if (format[i + 1] == arguments[j].specifier)
				{
					count += arguments[j].print(list);
					i++;
					break;
				}
			}
			if (arguments[j].specifier == 0 && format[i + 1] != ' ')
			{
				if (format[i + 1] != 0)
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
					i++;
				}
				else
					return (-1);
			}
		}
	}
	va_end(list);
	return (count);
}
