#include <stdio.h>
#include <assert.h>

// Use char for sake of verifying/clarity.
unsigned char rightrot(unsigned char x, int n) {
    unsigned char rb;
    while (n-- > 0) {
        rb = x & 1;
        x >>= 1;
        if (rb) {
            x |= 1 << (8 * sizeof(x) -1);
        }
    }
    return x;
}

int main() {
    // 10011100 -> 00100111
    assert(rightrot(156, 2) == 39);
    // 01110100 -> 10100011
    assert(rightrot(116, 5) == 163);
    return 0;
}
