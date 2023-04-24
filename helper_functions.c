#include "main.h"
#include <stdio.h>

/**
 * print_hex - prints a decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_hex(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

/**
 * print_int - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_int(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

/**
 * prinlhex - prints a long decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinlhex(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, long int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

/**
 * prinlint - prints a long integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinlint(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input;
	unsigned long int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, long int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

/**
 * prinloct - prints long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinloct(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(arguments, long int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = fill_long_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
