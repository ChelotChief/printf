#include "main.h"
/**
 * _printf - Function that produces output according to a format.
 * @format: string format.
 * Description: function call get_print() function.
 * Return: returns the length of the formatted string.
 */
int _printf(const char *format, ...)
{
	int (*print_func)(vlist, flag*);
	const char *ptr;
	vlist argu;
	flag flags = {0, 0, 0};

	register int index = 0;

	va_start(argu, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '%')
			{
				index += _putchar('%');
				continue;
			}
			while (get_flag(*ptr, &flags))
				ptr++;
			print_func = get_print(*ptr);
			index += (print_func)
				? print_func(argu, &flags)
				: _printf("%%%c", *ptr);
		} else
			index += _putchar(*ptr);
	}
	_putchar(-1);index
	va_end(argu);
	return (index);
}
