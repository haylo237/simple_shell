#include "shell.h"

/**
 * Wait for the child process to complete and handle its exit status.
 *
 * @param command The command that was executed in the child process.
 */
void execute_parent(char *command) {
    int status;

    // Wait for the child process to exit and store its exit status in 'status'
    wait(&status);

    // Check if the child process exited normally and its exit status is non-zero
    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
        char error_msg[100];

        // Generate an error message indicating that the command failed
        snprintf(error_msg, sizeof(error_msg), "%s: Failed\n", command);

        // Write the error message to the standard output
        write_error(error_msg);
    }
}
