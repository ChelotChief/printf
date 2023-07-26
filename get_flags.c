#include "main.h"

/**
 * get_flags - Function that calculates active flags
 * @format: Formatted string in which to print the arguments.
 * @i: parameter.
 *
 * Return: returns active flags.
 */
int get_flags(const char *format, int *i)
{
	int count, curr_i;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	curr_i = *i + 1;
	while (format[curr_i] != '\0')
	{
		for (count = 0; FLAGS_CHAR[count] != '\0'; count++)
			if (format[curr_i] == FLAGS_CHAR[count])
			{
				flags |= FLAGS_ARRAY[count];
				break;
			}

		if (FLAGS_CHAR[count] == 0)
			break;

		curr_i++;
	}

	*i = curr_i - 1;

	return (flags);
}
