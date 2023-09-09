#include "shell.h"

/**
 * Execute a child process with the specified command and arguments.
 *
 * @param command The full path to the command to be executed.
 * @param args An array of strings representing the command and its arguments.
 *
 * This function is responsible for executing the specified command in a child process.
 * It takes the full path to the command as `command` and an array of strings `args`
 * representing the command and its arguments. The `execve` system call is used to
 * execute the command with the given arguments. If the execution fails, an error message
 * is printed, and the child process exits with a failure status.
 */
void execute_child(char *command, char *args[]) {
    char *envp[] = {NULL};

    if (execve(command, args, envp) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

