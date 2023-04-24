#include "main.h"

/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _write_char('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
 * print_unsgined_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsgined_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
 * print_add - prints the address of a pointer
 * @list: address of pointer
 * Return: The number of printed characters
 */
int print_add(va_list list)
{
	void *ptr = va_arg(list, void*);
	char buffer[1024];
	int index = 0;

/*Convert the pointer value to a string*/
	uintptr_t address = (uintptr_t)ptr;

	do {
		buffer[index++] = "0123456789abcdef"[address % 16];
		address /= 16;
	} while (address != 0);

/*Print the string in reverse order*/
	int printed_chars = 0;

	for (int i = index - 1; i >= 0; i--)
	{
		_write_char(buffer[i]);
		printed_chars++;
	}
	return (printed_chars);
}
