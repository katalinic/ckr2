#include <stdio.h>

#define MAX_SIZE 1024  /* Max line length, including termination char. */

void reverse(char src[]) {
    int l, i, j;
    char tmp;

    l = 0;
    while ((src[l] != '\0')) ++l;

    j = l-1;
    for (i = 0; i < j; i++) {
        tmp = src[i];
        src[i] = src[j];
        src[j] = tmp;
        --j;
    }

    src[l + 1] = '\0';
}

int main() {
    int c, i;
    char buf[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        buf[i] = c;
    }
    buf[i] = '\0';

    reverse(buf);

    printf("%s", buf);

    return 0;
}
