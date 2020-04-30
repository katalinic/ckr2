#include <stdio.h>

#define MAX_LINE_SIZE 1000

int custom_getline(char dst[], int length_limit) {
    int c, i;

    for (i = 0; i < length_limit - 1; ++i) {
        if ((c = getchar()) == EOF) {
            break;
        } else if (c == '\n') {
            dst[i++] = '\n';
            break;
        }
        dst[i] = c;
    }
    dst[i] = EOF;
    return i;
}

void copy(char src[], char dst[]) {
    int i = 0;
    while ((dst[i] = src[i]) != '\0') ++i;
}

int main() {
    int i, l = 0, ml = 0;
    char longest_line[MAX_LINE_SIZE];
    char buffer[MAX_LINE_SIZE];

    while ((l = custom_getline(buffer, MAX_LINE_SIZE)) > 0) {
        printf("found line of length %d\n", l);
        if (l > ml) {
            copy(buffer, longest_line);
            ml = l;
        }
    }

    if (ml > 0) {
        printf("%s", longest_line);
    }

    return 0;
}
