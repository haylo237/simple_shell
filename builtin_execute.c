#include "shell.h"
/**
 * builtin_execute - executes the built-in functions
 * @tokens: arguments being passed
 * Return: status code
 */
int builtin_execute(char **tokens)
{
    int status;
    unsigned int length;
    unsigned int num;
    unsigned int i = 0;

    built_s builtin[] = {
        {"exit", shell_exit},
        {"env", shell_env},
        {NULL, NULL}
    };

    if (tokens[0] == NULL)
        return (1);

    length = _strlen(tokens[0]);

    num = shell_num_builtins(builtin);

    while (i < num)
    {
        if (_strcmp(tokens[0], builtin[i].name, length) == 0)
        {
            status = (builtin[i].p)();
            return (status);
        }
        i++;
    }
    return (1);
}

/**
 * shell_num_builtins - this checks the number of built-ins
 * @builtin: an array of built-ins
 * Return: number of built-ins
 */
int shell_num_builtins(built_s builtin[])
{
    unsigned int i = 0;

    while (builtin[i].name != NULL)
        i++;

    return (i);
}

