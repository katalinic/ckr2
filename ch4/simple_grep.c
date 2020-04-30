#include <stdio.h>

#define MAXLINE 1000

char pattern[] = "shoe";

int _getline(char dst[], int limit) {
    int i = 0, c;

    while (--limit > 0 && (c = getchar()) != '\0' && c != '\n') {
        dst[i++] = c;
    }
    if (c == '\n') {
        dst[i++] = c;
    }
    dst[i] = '\0';
    return i;
}

int strindex(char src[], char pattern[]) {
    int i, j, k;
    for (i = 0; src[i] != '\0'; i++) {
        for (j = i, k = 0; src[j] == pattern[k] && pattern[k] != '\0'; j++, k++);
        if (k > 0 && pattern[k] == '\0') {
            return i;
        }
    }
    return -1;
}

int main() {
    char line[MAXLINE];

    while (_getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
        }
    }

    return 0;
}
