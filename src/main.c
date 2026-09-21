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

        char *args[64];
        int argc = 0;
        char *token = strtok(line, " \t\r\n");

        while (token != NULL && argc < 63) {
            args[argc] = token;
            argc++;
            token = strtok(NULL, " \t\r\n");
        }

        args[argc] = NULL;

        if (token != NULL) {
            fprintf(stderr, "lsh: 最多支持 63 项（包含命令名）\n");
            continue;
        }

        for (int i = 0; i < argc; i++) {
            printf("args[%d] = %s\n", i, args[i]);
        }

        printf("共 %d 项，args[%d] = NULL\n", argc, argc);
    }

    free(line);
    return 0;
}
