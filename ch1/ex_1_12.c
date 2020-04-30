#include <stdio.h>

#define IN 0
#define OUT 1

int main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = IN;
            continue;
        } else if (state == IN) {
            putchar('\n');
            state = OUT;
        }
        putchar(c);
    }

    return 0;
}
