#include <stdio.h>

#define NUM_LETTERS 26

int main() {
    int c, i, n;
    int cfreqs[NUM_LETTERS]; // Assuming just letters.

    for (i = 0; i < NUM_LETTERS; ++i) {
        cfreqs[i]=0;
    }

    while((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++cfreqs[c-'a'];
        }
    }

    for (i = 0; i < NUM_LETTERS; ++i) {
        printf("%c ", 'a'+i);
        for (n = 0; n < cfreqs[i]; ++n) {
            printf("-");
        }
        printf("\n");
    }
}
