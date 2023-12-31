#include "main.h"
/**
 * print_pointer - Function that print
 * the value of a pointer variable.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_char = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;

	index++;
	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_char, padd_start));
}
/**
 * print_non_printable - Function that prints ascii
 * codes in hexa of non printable chars.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Print number of chars.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[index] != '\0')
	{
		if (is_printable(str[index]))
			buffer[index + offset] = str[index];
		else
			offset += append_hexa_code(str[index], buffer, index + offset);

		index++;
	}

	buffer[index + offset] = '\0';

	return (write(1, buffer, index + offset));
}
/**
 * print_reverse - Function that prints reverse string.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars.
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int index, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (index = 0; str[index]; index++)
		;

	for (index = i - 1; index >= 0; index--)
	{
		char z = str[index];

		write(1, &z, 1);
		count++;
	}
	return (0);
}
/**
 * print_rot13string - Function thqt prints a string in rot13.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars.
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
