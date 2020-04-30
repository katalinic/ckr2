#include <stdio.h>
#include <assert.h>

int strend(char *s, char *t) {
    char *i = s, *j = t;

    while (*s++);
    while (*t++);

    while (s > i && t > j && *--s == *--t);
    return (t == j && *s == *t) ? 1: 0;
}

int main() {
    assert(strend("abcde", "de"));
    assert(!strend("abcde", "bde"));
    assert(!strend("bc", "abc"));
    assert(strend("", ""));
    return 0;
}
