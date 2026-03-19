#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
    char line[MAX_LINE];

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0) {
            break;
        }

        printf("%s\n", line);
    }

    return 0;
}
