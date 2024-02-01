#include "main.h"
/**
 * main : is entry point to print char & strings & %
 *
 * return : the numbers of printed items
 *
 **/
int _printf(const char *format, ...)
{
	int i = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			i++;
		}
		else
		{
			switch (*++format)
			{
				case 'c':
					i += fprintf(stdout, "%c", va_arg(args, int));
					break;
				case 's':
					i += fprintf(stdout, "%s", va_arg(args, char *));
					break;
				default:
					putchar(*format);
					i += 2;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (i);
}
int main()
{
printf("the value of char is %c\n", 'x');
_printf("the value of char is %c\n", 'x');
printf("the value of string is %s\n", "hello");
_printf("the value of string is %s\n", "hello");
printf("the value of percentage is %% \n");
_printf("the value of percentage is %% \n");
return (0);
}
