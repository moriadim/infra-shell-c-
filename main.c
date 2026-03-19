#include "shell.h"

int main() {
    char line[MAX_LINE];
    char **args;
    int status;

    do {
        printf("infra-sh> ");
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
