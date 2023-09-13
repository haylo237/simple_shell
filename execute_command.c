#include "shell.h"

/**
 * execute_command - Execut a command line.
 * @command_line: The command line to be executed, which may include the command and its arguments.
 */
void execute_command(char *command_line)
{
	char *path, *path_copy, *path_token;
	char *args[MAX_ARGS + 2];
	int num_args = 0;
	char *token = strtok(command_line, " ");

	while (token != NULL && num_args < MAX_ARGS)
	{
		args[num_args] = token;
		num_args++;
		token = strtok(NULL, " ");
	}

	args[num_args] = NULL;

	if (num_args == 0)
	{
		return;
	}

	if (strcmp(command_line, "exit") == 0) exit (0);

	path = getenv("PATH");
	if (path == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		char command_path[1024];
	
		snprintf(command_path, sizeof(command_path), "%s/%s", path_token, args[0]);

		if (access(command_path, X_OK) == 0)
		{
			handle_command(command_path, args);
			free(path_copy);
			return;
		}

		path_token = strtok(NULL, ":");
        }

    free(path_copy);
    write_error("Command not found\n");
}
