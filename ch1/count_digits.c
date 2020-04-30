#include <stdio.h>

int main() {
    int c, i;
    int ndigit[10];

    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            printf("%d\n", c);
            ++ndigit[c-'0'];
        }
    }
    printf("Digit | Count\n");
    for (i = 0; i < 10; ++i) {
        printf("%d \t %d\n", i, ndigit[i]);
    }
}
