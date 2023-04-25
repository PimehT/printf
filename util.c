#include "main.h"

/**
 * is_printable - checks if char is printable
 * @c: char to check
 *
 * Return: 1 on success, otherwise 0
 */
int is_printable(char c);
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - appends ascii in hexa code to buffer
 * @buffer: array of chars
 * @i: index to start appending
 * @ascii_code: ascii code
 *
 * Return: on success, 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if char is a digit
 * @c: char to check
 *
 * Return: 1 on success, otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}


