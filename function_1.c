#include "main.h"
/**
 * print_unsigned -  Function that prints
 * an unsigned number.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns number of chars.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[index—] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
/**
 * print_octal - Function that prints an
 * unsigned number in octal notation.
 * @types: List  of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[index--] = '0';

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Function that prints
 * an unsigned number in hexadecimal notation
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Function that prints an unsigned
 * number in upper hexadecimal notation.
 * @types: List of arguments.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * Return: Returns the number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - Function that prints a hexadecimal
 * number in lower or upper.
 * @types: List of arguments.
 * @map_to: Array of values to map.
 * @buffer: Buffer array.
 * @flags:  Calculates active flags.
 * @flag_ch: Calculates active flags.
 * @width: width.
 * @precision: Precision specification variable.
 * @size: Size specifier variable.
 * @size: Size specification variable.
 * Return: Returns the number of chars.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int i_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && i_num != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] = '0';
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
