#include <stdio.h>

#define ALLOC_SIZE 10000
#define KB 1<<10

char allocbuf[ALLOC_SIZE];
char *allocp = &allocbuf[0];

char *alloc(int n) {
    if (allocp - &allocbuf[0] + n >= ALLOC_SIZE) {
        return 0;
    } else {
        allocp += n;
        return allocp - n;
    }
}

void afree(char *p) {
    if (p >= &allocbuf[0] && p < &allocbuf[0] + ALLOC_SIZE) {
        allocp = p;
    }
}

int main() {
    char *p;

    p=alloc(KB);
    printf("Buffer begins at %p\n", &allocbuf[0]);
    printf("Allocated section begins at %p\n", p);
    printf("Free space post-allocation begins at %p\n", allocp);

    afree(p);
    printf("Free space post-release begins at %p\n", allocp);

    return 0;
}
