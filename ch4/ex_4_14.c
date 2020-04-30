#include <stdio.h>

#define SWAP(t, x, y) {t temp; temp = x; x = y; y = temp;}

int main() {
    int a = 13, b = 42;
    printf("Pre-swap: %d %d\n", a, b);
    SWAP(int, a, b);
    printf("Post-swap: %d %d", a, b);
    return 0;
}
