#include "main.h"

/**
 * print_unsigned - prints an usigned number
 * @types: list of arguments
 * @buffer: buffer array handling print
 * @flags: calculates the flags active
 * @width: width
 * @precision: precision specified
 * @size: size specified
 *
 * Return: number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints in octal notation
 * @types: list of arguments
 * @buffer: buffer array handling print
 * @flags: calculates the flags active
 * @width: width
 * @precision: precision specified
 * @size: size specified
 *
 * Return: number of chars printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints in hexa notation
 * @types: list of arguments
 * @buffer: buffer array handling print
 * @flags: calculates the flags active
 * @width: width
 * @precision: precision specified
 * @size: size specified
 *
 * Return: number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - prints int upper hexa notation
 * @types: list of arguments
 * @buffer: buffer array handling print
 * @flags: calculates the flags active
 * @width: width
 * @precision: precision specified
 * @size: size specified
 *
 * Return: number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - prints in either lower of upper hexa
 * @types: list of arguments
 * @map_to: array of values to map number to
 * @buffer: buffer array handling print
 * @flags: calculates the flags active
 * @flag_ch: calculates flags active too
 * @width: width
 * @precision: precision specified
 * @size: size specified
 *
 * Return: number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
