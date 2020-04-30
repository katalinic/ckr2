#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char tmp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void itob(int n, char s[], int b) {
    char ans[] = "0123456789abcdef";
    int i = 0, sign;
    if ((sign = n) < 0) {
        n = -n;
    }

    do {
        s[i++] = ans[n % b];
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char buffer[10];
    itob(0, buffer, 16);
    assert(!strcmp(buffer, "0"));
    itob(15, buffer, 16);
    assert(!strcmp(buffer, "f"));
    itob(16, buffer, 16);
    assert(!strcmp(buffer, "10"));
    itob(-42, buffer, 16);
    assert(!strcmp(buffer, "-2a"));
    return 0;
}
