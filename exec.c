#include "shell.h"

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1; // Empty command
    }

    // Built-in commands handling
    if (strcmp(args[0], "exit") == 0) {
        return 0; // Signal main loop to terminate
    }

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "infra-sh: expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("infra-sh: cd");
            }
        }
        return 1;
    }

    // Easter Egg Command
    if (strcmp(args[0], "about") == 0) {
        printf("Infra-Shell-C by Abdellah - ESTIN 2026\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child Process
        if (execvp(args[0], args) == -1) {
            // Include shell name for a customized error
            fprintf(stderr, "infra-sh: command not found: %s\n", args[0]);
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("infra-sh: fork");
    } else {
        // Parent Process: wait for child
        // WUNTRACED allows parent to return if child process is stopped
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}
