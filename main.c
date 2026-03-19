#include "shell.h"

/**
 * @brief The main loop displaying the prompt and executing commands.
 * 
 * @return int Exit status of the shell program.
 */
int main() {
    char line[MAX_LINE];
    char **args;
    int status;

    do {
        printf(ANSI_COLOR_CYAN "infra-sh> " ANSI_COLOR_RESET);
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; // Handle EOF securely
        }

        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0) {
            continue;
        }

        args = split_line(line);
        status = execute_command(args);

        free(args);
    } while (status);

    return 0;
}
