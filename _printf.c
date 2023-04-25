#include <stdarg.h>
#include <string.h>
#include <stdio.h>


int print_number(int n, int base, int is_signed);
int print_hex(unsigned int n, int uppercase);
int print_pointer1(void *p);
/**
 int _putchar(char c);



 * _putchar - writes char c to stdout

 * @c: the char to print

 * Return: on success 1

 * on error, -1 is retirned

 

int _putchar(char c)

{

	return (write(1, &c, 1));
*/



int len;
int i;
/**

 * _printf - A custom implementation of printf

 * @format: A string containing zero or more directives to be printed

 *

 * Return: The numer of characters printed (excluding the null byte used to end

 * the output to strings), or a negative value if an error occurs.

 */

int _printf(const char *format, ...)

{

    va_list args;

    int printed = 0, i = 0;

    char *s = NULL, *out = NULL, c = '\0', type = '\0';

    /*unsigned int u = 0;*/

    void *ptr = NULL;

    if (!format || (format[0] == '%' && format[1] == '\0'))

        return (-1);

    va_start(args, format);

    for (i = 0; format[i]; i++)

    {

        if (format[i] == '%')

        {

            i++;

            if (format[i] == '\0')

                return (-1);

            type = format[i];

            switch (type)

            {

                case 'c':

                    c = (char) va_arg(args, int);

                    out = &c;

                    len = 1;

                    break;

                case 's':

                    s = va_arg(args, char *);

                    if (s == NULL)

                        s = "(null)";

                    out = s;

                    len = strlen(out);

                    break;

                case 'd':

                case 'i':

                    printed += print_number(va_arg(args, int), 10, 1);

                    break;

                case 'u':

                    printed += print_number(va_arg(args, unsigned int), 10, 0);

                    break;

                case 'o':

                    printed += print_number(va_arg(args, unsigned int), 8, 0);

                    break;

                case 'x':

                case 'X':

                    printed += print_hex(va_arg(args, unsigned int), (type == 'X'));

                    break;

                case 'p':

                    ptr = va_arg(args, void *);

                    printed += print_pointer1(ptr);

                    break;

                case '%':

                    putchar('%');

                    printed++;

                    break;

                case '\0':

                    return (-1);

                default:

                    putchar('%');

                    putchar(type);

                    printed += 2;

                    break;

            }

        }

        else

        {

            putchar(format[i]);

            printed++;

        }

    }

    va_end(args);

    return (printed);

}

/**

 * print_number - Prints an integer to stdout

 * @n: The integer to print

 * @base: The base to use when printing the integer

 * @signed_: Whether or not the integer is signed

 *

 * Return: The number of characters printed

 */

int print_number(int n, int base, int signed_)

{

    int count = 0;

    unsigned int num = (signed_ && n < 0) ? -n : n;

    char digits[] = "0123456789abcdef";

    if (signed_ && n < 0)

        putchar('-'), count++;

    if (num / base)

        count += print_number(num / base, base, 0);

    putchar(digits[num % base]);

    count++;

    return (count);

}

/**

 * print_hex - Prints a number in hexadecimal form to stdout

 * @n: The number to print

 * @uppercase: Whether or not to print in uppercase

 *

 * Return: The number of characters printed

 */

int print_hex(unsigned int n, int uppercase)

{

    int count = 0;

    char *digits = "0123456789abcdef";

    if (uppercase)

    digits = "0123456789ABCDEF";

    if (n / 16)

        count += print_hex(n / 16, uppercase);

    putchar(digits[n % 16]);

    count++;

    return (count);

}

/**

 * print_pointer - Prints a pointer address in hexadecimal form to stdout

 * @ptr: The pointer to print

 *

 * Return: The number of characters printed

 */

int print_pointer(void *ptr)

{

    int count = 0;

    unsigned long int n = (unsigned long int) ptr;

    char digits[] = "0123456789abcdef";

    count += printf("0x");

    if (n / 16)

        count += print_hex(n / 16, 0);

    putchar(digits[n % 16]);

    count++;

    return (count);

}

/**

 * print_pointer - Prints a pointer address to stdout

 * @ptr: The pointer to print

 *

 * Return: The number of characters printed

 */

int print_pointer1(void *ptr)

{

    unsigned long int address = (unsigned long int) ptr;

    int count = 0;

    count += printf("0x%lx", address);

    return (count);

}
/**

 * _putchar - writes char c to stdout

 * @c: the char to print

 * Return: on success 1

 * on error, -1 is retirned

 */

int _putchar(char c)

{

	return (write(1, &c, 1));
}
