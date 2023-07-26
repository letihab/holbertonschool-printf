#include "main.h"

/**
 *my_printf - function that produces output according to a format
 *@format: parameter to convert
 *Return: 0.
 */
void my_printf(const char* format, ...)
{
	va_list args;
    va_start(args, format);

    unsigned int u;
    const char* s;
    char c;

    while ((c = *format++) != '\0') {
        if (c != '%') {
            putchar(c);
        } else {
            c = *format++;
            switch (c) {
                case 'u':
                    u = va_arg(args, unsigned int);
                    printf("%u", u);
                    break;
                case 'o':
                    u = va_arg(args, unsigned int);
                    printf("%o", u);
		     break;
                case 'x':
                    u = va_arg(args, unsigned int);
                    printf("%x", u);
                    break;
                case 'X':
                    u = va_arg(args, unsigned int);
                    printf("%X", u);
                    break;
                default:
                    putchar('%');
                    putchar(c);
            }
        }
    }

    va_end(args);
}

int main() {
    unsigned int u_value = 42;
    my_printf("Value as unsigned decimal: %u\n", u_value);
    my_printf("Value as octal: %o\n", u_value);
    my_printf("Value as lowercase hexadecimal: %x\n", u_value);
    my_printf("Value as uppercase hexadecimal: %X\n", u_value);

    return 0;
}
