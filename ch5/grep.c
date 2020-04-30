#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *buf = NULL;
    ssize_t len = 0;

    if (argc == 2) {
        while (getline(&buf, &len, stdin) > 0) {
            if (strstr(buf, argv[1]) != NULL) {
                printf("%s\n", buf);
            }
        }
    }
    free(buf);

    return 0;
}
