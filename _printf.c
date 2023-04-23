#include "main.h"

/**
 * _printf - Receives the main string and all parameters
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int char_nums;
	switch_va switch_case[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list varList;

	if (format == NULL)
		return (-1);

	va_start(varList, format);

	char_nums = decode(format, switch_case, varList);
	va_end(varList);
	return (char_nums);
}
