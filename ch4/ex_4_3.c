#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SINGLE_ARGUMENT_SIZE 100
#define NUMBER '0'
#define MAX_STACK_DEPTH 100

int dsp=0, chsp=0;
double dstack[MAX_STACK_DEPTH];
char chstack[MAX_STACK_DEPTH];

void push(double x) {
    if (dsp < MAX_STACK_DEPTH) {
        dstack[dsp++] = x;
    } else {
        printf("double stack full\n");
    }
}

double pop(void) {
    if (dsp) {
        return dstack[--dsp];
    } else {
        printf("double stack empty\n");
        return 0.0;
    }
}

int getch(void) {
    return (chsp)? chstack[--chsp] : getchar();
}

void ungetch(char c) {
    if (chsp < MAX_STACK_DEPTH) {
        chstack[chsp++] = c;
    } else {
        printf("char stack full\n");
    }
}

int getop(char buf[]) {
    int i = 0;
    char c, next;

    while ((c = getch()) == ' ' || c == '\t');
    buf[0] = c;
    buf[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    if (c == '-') {
        next = getch();
        ungetch(next);
        if (!isdigit(next) && next != '.') {
            return c;
        }
        c = next;
    }
    if (isdigit(c)) {
        while (isdigit(buf[++i] = c = getch()));
    }
    if (c == '.') {
        while (isdigit(buf[++i] = c = getch()));
    }
    buf[i] = '\0';
    return NUMBER;
}

int main() {
    int type;
    double op2;
    char buf[MAX_SINGLE_ARGUMENT_SIZE];

    while ((type = getop(buf)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(buf));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("zero division error\n");
                } else {
                    push(pop() / op2);
                }
                break;
            case '%':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("zero modulo error\n");
                } else {
                    push(fmod(pop(), op2));
                }
                break;
            case '\n':
                printf("%f\n", pop());
                break;
            default:
                printf("encountered invalid operator %c", type);
                return 0;
        }
    }

    return 0;
}
