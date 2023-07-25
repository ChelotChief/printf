#include "main.h"

/**
 * get_precision - Function that calculates the precision for printing.
 * @format: Formatted string.
 * @i: List of arguments.
 * @list: list of arguments.
 *
 * Return: Returns precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_index = *i + 1;
	int pre = -1;

	if (format[curr_index] != '.')
		return (pre);

	pre = 0;

	curr_index += 1;
	while (format[curr_index] != '\0')
	{
		if (is_digit(format[curr_index]))
		{
			pre *= 10;
			pre += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			pre = va_arg(list, int);
			break;
		}
		else
			break;
			curr_index++;
	}

	*i = curr_index - 1;

	return (pre);
}
