#include <stdio.h>

int power(int m, int n);

int main() {
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

int power(int m, int n) {
    int i, res;

    res = 1;
    for (i = 0; i < n; i++) {
        res = res * m;
    }

    return res;
}
