#include "shell.h"

/**
 * handle_command - Execute a command in a child process.
 * @command_path: The full path to the command to be executed.
 * @args: An array of strings representing the command and its arguments.
 * Return: Void
 */
void handle_command(char *command_path, char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execute_child(command_path, args);
	}
	else
	{
		execute_parent(args[0]);
	}
}
