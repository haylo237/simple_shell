#include "shell.h"

/**
 * Execute a command line.
 *
 * @param command_line The command line to be executed, which may include the command and its arguments.
 */
void execute_command(char *command_line) {
	char *path, *path_copy, *path_token;
	char *args[MAX_ARGS + 2]; // +2 for the command and NULL terminator
    int num_args = 0;

    char *token = strtok(command_line, " ");
    while (token != NULL && num_args < MAX_ARGS) {
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " ");
    }
    args[num_args] = NULL; // Null-terminate the args array

    if (num_args == 0) {
        return; // No command provided
    }

    // Check if the command exists in the PATH
    path = getenv("PATH");
    if (path == NULL) {
        perror("getenv");
        exit(EXIT_FAILURE);
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    path_token = strtok(path_copy, ":");
    while (path_token != NULL) {
        char command_path[1024];
        snprintf(command_path, sizeof(command_path), "%s/%s", path_token, args[0]);

        if (access(command_path, X_OK) == 0) {
            // Command found in the current path, call the function to handle command execution
            handle_command(command_path, args);
            free(path_copy);
            return;
        }

        path_token = strtok(NULL, ":");
    }

    // If the loop completes, the command was not found in the PATH
    free(path_copy);
    write_error("Command not found\n");
}

