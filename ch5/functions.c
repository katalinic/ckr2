#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int (*fnPtr)(int, int) = &sum;
    printf("%d\n", (*fnPtr)(4, 7));

    return 0;
}
