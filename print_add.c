#include "main.h"

/**
 * print_add - prints an address specifier
 * @list: input address
 * Return: Number of printed characters
 */
int print_add(va_list list)
{
	void *add;
	int len;

	add = va_arg(list, void *);

	if (!add)
	{
		return (1);
	}
	else
	{
		len += _write_char('0');
		len += _write_char('x');
		len += print_hex(list);
		return (len);
	}
}
