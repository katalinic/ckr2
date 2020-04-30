#include <stdio.h>
#include <assert.h>

unsigned int set_bits(unsigned int x, int p, int n, int y) {
    x &= ~(((1 << n) - 1) << (p - n + 1));
    x |= (y & ((1 << n) - 1)) << (p - n + 1);
    return x;
}

int main() {
    // 100101; replace 010 with y=10101 to get 101011
    assert(set_bits(37, 3, 3, 21) == 43);
    return 0;
}
