#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 10

int getint(int *p) {
    int c, sign;

    while (isspace(c = getc(stdin)));
    if (!isdigit(c) && c != '-' && c != '+') {
        ungetc(c, stdin);
        return 0;
    }

    sign = (c == '-')? -1: 1;
    if (c == '-' || c == '+') {
        if (!isdigit(c = getc(stdin))) {
            ungetc(c, stdin);
            return 0;
        }
    }
    for (*p = 0; isdigit(c); c = getc(stdin)) {
        *p = *p * 10 + c - '0';
    }
    *p = *p * sign;
    if (c != EOF) ungetc(c, stdin);
    return 1;
}

int main() {
    int i, buf[MAX_SIZE];

    for (i = 0; i < MAX_SIZE && getint(&buf[i]); i++);
    for (int j = 0; j < i; j++){
        printf("%d\n", buf[j]);
    }

    return 0;
}
