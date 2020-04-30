#include <stdio.h>
#include <assert.h>

unsigned int get_bits(unsigned int x, int p, int n) {
    return (x >> (p - n + 1)) & ((1 << n) - 1);
}

int main() {
    // 11 = 001011;
    assert(get_bits(11, 3, 2) == 2);

    // 105 = 1101001
    assert(get_bits(105, 5, 6) == 41);
    assert(get_bits(105, 3, 3) == 4);

    return 0;
}
