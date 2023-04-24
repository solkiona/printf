#include "main.h"

/**
 * print_add - prints the address of a pointer
 * @list: address of pointer
 * Return: The number of printed characters
 */
int print_add(va_list list)
{
	void *ptr = va_arg(list, void*);
	char buffer[16];
	int index = 0;
/*Convert the pointer value to a string*/

	uintptr_t address = (uintptr_t)ptr;

	do {
		buffer[index++] = "0123456789abcdef"[address % 16];
		address /= 16;
	} while (address != 0);

	if (index >= PRINT_ADD_BUFFER_SIZE)
		return (-1);

/*Print the string in reverse order*/
	int printed_chars = 0;

	for (int i = index - 1; i >= 0; i--)
	{
		_write_char(buffer[i]);
		printed_chars++;
	}
	return (printed_chars);
}
