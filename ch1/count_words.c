#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, in_word;

    in_word = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') ++nl;
        if (c == '\n' || c == ' ' || c == '\t')
            in_word = OUT;
        else if (in_word == OUT) {
            ++nw;
            in_word = IN;
        }
    }
    printf("line count: %d, word count: %d, char count: %d", nl, nw, nc);
    return 0;
}
