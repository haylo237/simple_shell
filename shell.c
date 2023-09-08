#include "shell.h"
/**
 * Main - Entry point
 * Return: Always 0
 */
int main(void)
{
	char input[100];
	for (;;)
	{
		write_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			// Handle Ctrl+D (EOF)
            write(STDOUT_FILENO, "\n", 1);
            break;
		}
		// Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            // Empty input, continue to the next iteration
            continue;
        }

        execute_command(input);
    }

    return 0;
}
