#include "main.h"

/**
 *_printf - function that produces output according to a format
 *@format: parameter to specifie a type of entry
 *Return:the number of the characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list list;
	set arguments[] = {
		{"c", print_char},
		{"d", print_d},
		{"i", print_d},
		{"s", print_str},
		{"b", convert_b},
		{"o", convert_o},
		{"x", convert_hex},
		{"X", convert_HEX},
		{"r", rev_s},
		{"R", ROT13},
		{NULL, NULL},
	};

	if (format == NULL)
		return (-1);

	va_start(list, format);

	count = 0;

	count = get_functions(format, list, arguments);
	va_end(list);
	return (count);
}
