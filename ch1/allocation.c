#include <stdio.h>

#define NUM_ELEMENTS 10

int main() {
    char cbuf[NUM_ELEMENTS];
    int ibuf[NUM_ELEMENTS];

    printf("Allocated %d bytes for %d elements of char buffer \n", sizeof(cbuf), NUM_ELEMENTS);
    printf("Allocated %d bytes for %d elements of int buffer \n", sizeof(ibuf), NUM_ELEMENTS);

    return 0;
}
