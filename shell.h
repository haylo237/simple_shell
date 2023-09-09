#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10 // Maximum number of arguments



void write_prompt(void);
void write_error(const char *message);
void execute_command(char *command);
void execute_child(char *command, char *args[]);
void execute_parent(char *command);
void handle_command(char *command_path, char *args[]);


#endif /* SHELL_H */
