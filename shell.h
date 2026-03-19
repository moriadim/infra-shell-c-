#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

// Parse string into an array of tokens
char **split_line(char *line);

// Execute the parsed arguments and handle built-ins
int execute_command(char **args);

#endif // SHELL_H
