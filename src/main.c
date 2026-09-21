#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

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

        printf("你输入了：%s", line);
    }

    free(line);
    return 0;
}
