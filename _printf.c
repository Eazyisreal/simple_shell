#include "main.h"

/**
 * _printf - Prints a string to the std output stream
 *
 * @str: Incoming string
 *
 * Return: Number of strings printed
 */

int _puts(char *str)   /// _printf("%s": No file", argc[0])
{
	int i = 0;

	while(str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

int _printf(const char *format, ...)
{
	int i;

	va_list param;
	va_start(param, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch(format[i + 1])
			{
				case 's':
					_puts(va_arg(param, char *));
					i += 1;
					break;
				default:
					_putchar(format[i]);
					i++;
					break;
			}
			continue;
		}
		else
			_putchar(format[i]);
	}
	va_end(param);

	return (i);
}
