#include <stdio.h>
#include <ctype.h>

char letters[] = "abcdefghijklmnopqrstuvwxyz";
#define NLETTERS (sizeof letters / sizeof letters[0] - 1)

struct letterC {
    char x;
    int c;
};

struct letterC letterCounts[NLETTERS];

struct letterC *binsearch(struct letterC *v, char x, int n) {
    int cond;
    struct letterC *left = &v[0], *right = &v[n], *middle;
    while (left < right) {
        middle = left + (right - left) / 2;
        if ((cond = middle->x - x) < 0) {
            left = middle + 1;
        } else if (cond > 0) {
            right = middle;
        } else {
            return middle;
        }
    }
    return NULL;
}

int main() {
    for (int i = 0; i < NLETTERS; i++) {
        letterCounts[i].x = letters[i];
        letterCounts[i].c = 0;
    }

    struct letterC *p;
    char c;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if ((p = binsearch(letterCounts, c, NLETTERS)) != NULL) {
                p->c++;
            }
        }
    }

    for (p = letterCounts; p < letterCounts + NLETTERS; p++){
        printf("%c : %d\n", p->x, p->c);
    }

    return 0;
}
