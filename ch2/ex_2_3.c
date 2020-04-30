#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char s[]) {
    int ret = 0;
    int v = 0;
    int base = 1;
    char c = 0;
    int l = strlen(s);

    for (int i=0; i<l; ++i) {
        c = s[l-i-1];

        if (c == 'x' || c == 'X') {
            break;
        }

        if (isdigit(c)) {
            v = c - '0';
        } else if (tolower(c) >= 'a' && tolower(c) <= 'f') {
            v = 10 + c - 'a';
        } else {
            continue;
        }

        ret += v * base;
        base *= 16;
    }

    return ret;
}

int main() {
    printf("%s -> %d\n", "0x12", htoi("0x12"));
    printf("%s -> %d\n", "0xff", htoi("0xff"));
    printf("%s -> %d\n", "0xhh", htoi("0xhh"));
    printf("%s -> %d\n", "0x", htoi("0x"));
    printf("%s -> %d\n", "", htoi(""));
    return 0;
}
