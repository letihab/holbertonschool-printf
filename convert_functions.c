#include "main.h"

/**
 *custom_printf - output according to a format,
 *@format: parameter to test,
 *Return :nothing.
 */
void convert_f(const char *format, ...)
{
	unsigned int num;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
	{
            format++;
            switch (*format)
	    {
                case 'u':
                case 'o':
                case 'x':
                case 'X':
                    if (*format == 'u')
		    {
                        num = va_arg(args, unsigned int);
                        printf("%u", num);
                    }
		    else if (*format == 'o')
		    {
                   num = va_arg(args, unsigned int);
                        printf("%o", num);
                    }
		    else if (*format == 'x')
		    {
                         num = va_arg(args, unsigned int);
                        printf("%x", num);
                    }
		    else if (*format == 'X')
		    {
                       num = va_arg(args, unsigned int);
                        printf("%X", num);
                    }
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    break;
            }
        }
	else
	{
            putchar(*format);
        }

        format++;
    }

    va_end(args);
}
