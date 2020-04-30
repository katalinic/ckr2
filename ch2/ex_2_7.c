#include <stdio.h>
#include <assert.h>

unsigned int invert(unsigned int x, int p, int n) {
    return x ^ (((1 << n) - 1) << (p - n + 1));
}

int main() {
    // 110101, 3, 3 -> 111011
    // 110101, 4, 2 -> 101101
    assert(invert(53, 3, 3) == 59);
    assert(invert(53, 4, 2) == 45);
    return 0;
}
