#include "shell.h"
/**
 * main - Entry point
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
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0)
		{
			continue;
		}

		execute_command(input);
	}

	return (0);
}
