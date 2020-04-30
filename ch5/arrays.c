#include <stdio.h>

int main() {
    int arr[] = {4, 9, 0, 1, -3};
    int *p;

    p = arr;
    printf("p points to %p where value is %d\n", p, *p);
    p = &arr[0];
    printf("p points to %p where value is %d\n", p, *p);

    int offset = 2;
    printf("Element at offset %d is %d\n", offset, arr[offset]);
    printf("Element at offset %d is %d\n", offset, *(p + offset));

    p++;  // increment location
    printf("p points to %p where value is %d\n", p, *p);

    *p += 1; // increment value at location
    printf("p points to %p where value is %d\n", p, *p);

    return 0;
}
