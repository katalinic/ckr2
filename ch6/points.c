#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

double norm(struct point *pt) {
    return sqrt((double)pt->x * pt->x + (double)pt->y * pt->y);
}

int main() {
    struct point pt = {1, 1};
    printf("%f\n", norm(&pt));

    struct point *ptArr[] = {
        &pt{1, 1},
    };

    return 0;
}
