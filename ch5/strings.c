#include <stdio.h>
#include <assert.h>
#include <string.h>

void astrcpy(char *s, char *t) {
    /* Copy t to s.*/
    while ((*s++ = *t++) != '\0');
}

int astrcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') return 0;
    }
    return *s-*t;
}

int main() {
    char s[] = "abcde";
    char t[] = "fghij";

    astrcpy(s, t);
    assert(!strcmp(s, t));

    assert(astrcmp("abc", "abc") == 0);
    assert(astrcmp("abd", "abc") > 0);
    assert(astrcmp("abc", "abd") < 0);
    assert(astrcmp("ab", "abc") < 0);
    assert(astrcmp("abc", "ab") > 0);
    return 0;
}
