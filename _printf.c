#include "main.h"

/**
 *_printf - function that produces output according to a format
 *@format: parameter to specifie a type of entry
 *Return:the number of the characters printed
 */
int _printf(const char *format, ...)
{
	int i, j, count, find;
	va_list list;
	set arguments[] = {
		{'c', print_char},
		{'d', print_d},
		{'i', print_d},
		{'s', print_str},
		/*{'R', print_rot13},
		  {'r', print_rev},*/
	};

	if (format == NULL)
		return (-1);

	va_start(list, format);

	count = 0;

	for (i = 0; format[i]; i++)
	{
		find = 0;
		if (format[i] == '%')
		{
			for (j = 0; arguments[j].specifier; j++)
			{
				if (format[i + 1] == arguments[j].specifier)
				{
					count += arguments[j].print(list);
					find = 1;
					break;
				}
			}


		if (!find && format[i + 1] != '\0')
			{
				count += write(1, &format[i], 1);
			}
		i++;
	     }
		else
		{
			count += write(1, &format[i], 1);
		}
	}
	va_end(list);
	return (count);
}
