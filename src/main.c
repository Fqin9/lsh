#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *line = NULL;
    size_t capacity = 0;

    while (1) {
        printf("lsh> ");
        fflush(stdout);

        if (getline(&line, &capacity, stdin) == -1) {
            break;
        }

        char *token = strtok(line, " \t\r\n");
        int index = 0;

        while (token != NULL) {
            printf("第 %d 项：%s\n", index, token);
            index++;
            token = strtok(NULL, " \t\r\n");
        }
    }

    free(line);
    return 0;
}
