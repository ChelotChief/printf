#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Function that prints a function.
 * @format: format.
 * Return: Returns printed characters.
 */
int _printf(const char *format, ...)
{
	int index, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	index = 0;
	while (format && format[index] != '\0')
	{
		if (format[index] != '%')
		{
			buffer[buff_ind++] = format[index];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &index);
			width = get_width(format, &index, list);
			precision = get_precision(format, &index, list);
			size = get_size(format, &index);
			++index;
			printed = handle_print(format, &index, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
		index++;
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
