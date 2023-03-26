#include <main.h>
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_printed = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    {
                        char c = (char)va_arg(args, int);
                        putchar(c);
                        chars_printed++;
                    }
                    break;
                case 's':
                    {
                        char *s = va_arg(args, char *);
                        while (*s != '\0') {
                            putchar(*s);
                            s++;
                            chars_printed++;
                        }
                    }
                    break;
                case '%':
                    {
                        putchar('%');
                        chars_printed++;
                    }
                    break;
                default:
                    // unsupported conversion specifier
                    break;
            }
        } else {
            putchar(*format);
            chars_printed++;
        }
        format++;
    }

    va_end(args);

    return chars_printed;
}

