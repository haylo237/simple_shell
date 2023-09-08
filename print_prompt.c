#include "shell.h"
/**
 * write_prompt - display prompt
 * Return: void
 */
void write_prompt() 
{
    write(STDOUT_FILENO, "#cisfun$ ", 9);
}
