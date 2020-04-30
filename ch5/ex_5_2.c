#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 10

int getfloat(double *fp) {
    int c;
    double sign;

    while (isspace(c = getc(stdin)));
    if (!isdigit(c) && c != '-' && c != '+' && c != '.') {
        ungetc(c, stdin);
        return 0;
    }

    sign = (c == '-')? -1.0: 1.0;
    if (c == '-' || c == '+') {
        if (!isdigit(c = getc(stdin))) {
            ungetc(c, stdin);
            return 0;
        }
    }

    for (*fp = 0.0; isdigit(c); c = getc(stdin)) {
        *fp = *fp * 10.0 + c - '0';
    }
    if (c == '.') {
        c = getc(stdin);
        for (double d = 1.0; isdigit(c); c = getc(stdin)) {
            d /= 10.0;
            *fp = *fp + (c - '0') * d;
        }
    }
    *fp = *fp * sign;
    if (c != EOF) ungetc(c, stdin);
    return 1;
}

int main() {
    int i;
    double buf[MAX_SIZE];

    for (i = 0; i < MAX_SIZE && getfloat(&buf[i]); i++);
    for (int j = 0; j < i; j++){
        printf("%f\n", buf[j]);
    }

    return 0;
}
