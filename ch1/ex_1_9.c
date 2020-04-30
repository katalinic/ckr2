#include <stdio.h>

int main() {
    int c;
    int b;

    b = 0;
    while ((c = getchar()) != EOF) {
        if ((c == ' ') && b) {
            continue;
        }
        b = (c == ' ');
        putchar(c);
    }

    return 0;
}
