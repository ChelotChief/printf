#include "main.h"

/**
 * print_char - Function that prints a char
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: Width variable
 * @precision: Precision specification variable
 * @size: Size variable
 * Return: Returns the number of chars
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
/**
 * print_string - Function that prints a string.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width variable.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int string_length = 0, index;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision > 5)
			str = "      ";
	}

	while (str[string_length] != '\0')
		string_length++;

	if (precision >= 0 && precision < string_length)
		string_length = precision;

	if (width > string_length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], string_length);
			for (index = width - string_length; index > 0; index--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (index = width - string_length; index > 0; index--)
				write(1, " ", 1);
			write(1, &str[0], string_length);
			return (width);
		}
	}

	return (write(1, str, string_length));
}
/**
 * print_percent - Function Prints a percent sign
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width variable.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars.
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Function that prints int value.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width variable.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}

	index++;

	return (write_number(is_negative, index, buffer, flags, width, precision, size));
}
/**
 * print_binary - Function that prints
 * an unsigned number.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width variable.
 * @precision: Precision specification variable.
 * @size: Size specifier variable
 * Return: returns the number of char.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num, m, index, total;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = num / m;
	index = 1;
	while (index < 32)
	{
		m /= 2;
		a[index] = (num / m) % 2;
		index++;
	}
	for (index = 0, total = 0, count = 0; index < 32; index++)
	{
		total += a[index];
		if (total || index == 31)
		{
			char z = '0' + a[index];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
