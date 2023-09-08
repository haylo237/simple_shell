#include "shell.h"
/**
 * write_error - display errors
 * @message: message
 * Return: always 0
 */
void write_error(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
