#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct point *create() {
    struct point *t = malloc(sizeof(struct point));
    t->x = t->y = 1;
    printf("%d %d\n", t->x, t->y);
    return t;
}

int main() {
    struct point *p = NULL;
    p = create();
    printf("%p\n", p);
    printf("%d %d\n", p->x, p->y);
    free(p);
    
    return 0;
}
