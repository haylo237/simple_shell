#include "shell.h"

/**
 * Execute a command in a child process.
 *
 * @param command_path The full path to the command to be executed.
 * @param args An array of strings representing the command and its arguments.
 */
void handle_command(char *command_path, char *args[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        execute_child(command_path, args);
    } else { // Parent process
        execute_parent(args[0]);
    }
}
