#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "word.h"

int getword(char *buf, int lim) {
    char c, *w = buf;

    while (isspace(c = getc(stdin)));
    if (c != EOF) *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalpha(c = getc(stdin))) {
            ungetc(c, stdin);
            break;
        }
        *w = c;
    }
    *w = '\0';

    return buf[0];
}

char *astrdup(char *w) {
    char *b = malloc(strlen(w) + 1);
    if (b != NULL) {
        strcpy(b, w);
    }
    return b;
}
