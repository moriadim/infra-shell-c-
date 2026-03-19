#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1; // إدخال فارغ، نستمر في الحلقة
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0; // إشارة لإنهاء الحلقة
    }

    pid = fork();
    if (pid == 0) {
        // Child Process (العملية الابن)
        if (execvp(args[0], args) == -1) {
            perror("shell error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // خطأ أثناء الاستنساخ
        perror("shell error");
    } else {
        // Parent Process (العملية الأب)
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main() {
    char line[MAX_LINE];
    char **args;
    int status;

    do {
        printf("> ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = 0;

        args = split_line(line);
        status = execute_command(args);

        free(args);
    } while (status);

    return 0;
}
