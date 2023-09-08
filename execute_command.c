#include "shell.h"
/**
 * execute_command - executes command
 * @command: input command
 * Return: always 0
 */
void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        switch (pid) {
            case 0: // Child process
                {
                    char *args[] = {command, NULL};
                    char *envp[] = {NULL}; // Pass an empty environment
                    if (execve(command, args, envp) == -1) {
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                }
		break;
            default: // Parent process
                {
                    int status;
                    waitpid(pid, &status, 0);
                    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                        char error_msg[100];
                        snprintf(error_msg, sizeof(error_msg), "%s: Command not found or failed\n", command);
                        write_error(error_msg);
                    }
                }
                break;
	}
    }
}

