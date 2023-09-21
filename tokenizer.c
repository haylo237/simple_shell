#include "shell.h"
/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */
char **tokenizer(char *str)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char *) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
	}

	tokens[i] = NULL;

	return (tokens);
}

