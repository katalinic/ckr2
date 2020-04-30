#include <stdio.h>
#include <assert.h>

void astrcat(char *s, char *t) {
    while (*s++);
    s--;
    while ((*s++ = *t++));
}

int main() {
    char buf[10] = "abc";
    char t[] = "def";

    printf("%s\n", buf);
    astrcat(buf, t);
    printf("%s\n", buf);
    return 0;
}
