#include "main.h"

/**
 * _printf - my own printf function
 * @format: format specifier
 *
 * Return: strings like actual printf
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, char_printed = 0;
	int width, size, precision, flags, buff = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff++] = format[i];
			if (buff == BUFF_SIZE)
				print_buffer(buffer, &buff);
			char_printed++;
		}
		else
		{
			print_buffer(buffer, &buff);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap,
					buffer, flags, width,
					precision, size);
			if (printed == -1)
				return (-1);
			char_printed += printed;
		}
	}

	print_buffer(buffer, &buff);

	va_end(ap);

	return (char_printed);
}

/**
 * print_buffer - function to print buffer content
 * @buffer: char array
 * @buff: index of the next char, also represents length
 *
 * Return: nothing
 */
void print_buffer(char buffer[], int *buff)
{
	if (buff > 0)
		write(1, &buffer[0], *buff);

	*buff = 0;
}
