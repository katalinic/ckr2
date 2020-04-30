#include <stdio.h>
#include <assert.h>

int astrncmp(char *s, char *t, int n) {
    for (; *s == *t && n-- > 0; s++, t++) {
        if (!*s || !n) {
            return 0;
        }
    }
    return (n)? *s - *t: 0;
}

int main() {
    assert(astrncmp("abcde", "abcfg", 3)==0);
    assert(astrncmp("abcde", "abcfg", 4)<0);
    assert(astrncmp("a", "b", 0)==0);

    return 0;
}
