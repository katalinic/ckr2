#include <stdio.h>

int main() {
    int x = 1, y = 2;
    int *p;

    p = &x;
    y = *p;
    printf("y is now: %d\n", y);  // 1
    printf("still different memory addresses: %p %p\n", &x, &y);

    *p = *p+2;
    printf("x is now: %d\n", x); // 3

    return 0;
}
