#include "shell.h"

/**
 * execute_parent - Wait for the child process
 * to complete and handle its exit status.
 * @command: The command that was executed in the child process.
 * Return: Void
 */
void execute_parent(char *command)
{
	int status;

	wait(&status);

	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		char error_msg[100];

		snprintf(error_msg, sizeof(error_msg), "%s: Failed\n", command);

		write_error(error_msg);
	}
}
