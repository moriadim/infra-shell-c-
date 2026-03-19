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

// ANSI Color definitions
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 * @brief Splits a string into an array of tokens (arguments).
 * 
 * @param line The input string read from the user.
 * @return A null-terminated array of strings.
 */
char **split_line(char *line);

/**
 * @brief Executes the parsed arguments and handles shell built-ins.
 * 
 * @param args The null-terminated array of arguments (tokens).
 * @return 1 to continue shell execution, 0 to terminate loop.
 */
int execute_command(char **args);

#endif // SHELL_H
