#include "main.h"

/**
 * decode - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @switch_case: A list of all the posible functions.
 * @varList: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int decode(const char *format, switch_va switch_case[], va_list varList)
{
	int i, j, r_val, char_nums;

	char_nums = 0;
	for (i = 0; format[i] != '\0'; i++)/* Iterates through the main str*/
	{
		if (format[i] == '%') /*Checks for format specifiers*/
		{
			/*Iterates through struct to find the right func*/
			for (j = 0; switch_case[j]._case != NULL; j++)
			{
				if (format[i + 1] == switch_case[j]._case[0])
				{
					r_val = switch_case[j].call_func(varList);
					if (r_val == -1)
						return (-1);
					char_nums += r_val;
					break;
				}
			}
			if (switch_case[j]._case == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);
					char_nums = char_nums + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /*Updating i to skip format symbols*/
		}
		else
		{
			_write_char(format[i]); /*call the write function*/
			char_nums++;
		}
	}
	return (char_nums);
}
