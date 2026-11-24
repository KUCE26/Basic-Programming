#include <stdio.h>

void aim(int **pp, int *target) {
    *pp = target;
}

void bump(int *const q, int amount) {
    *q += amount;
}

int peek(const int *q) {
    return *q;
}

void swap_ptr(int **x, int **y) {
    int *t = *x;
    *x = *y;
    *y = t;
}

int main(void) {
    int a, b, c, m, k;
    char cmd;
    scanf("%d %d %d", &a, &b, &c);
    int *p = &a;
    int *r = &c;
    scanf("%d", &m);
    for (k = 0; k < m; k++) {
        scanf(" %c", &cmd);
        if (cmd == 'a') {
            aim(&p, &a);
        } else if (cmd == 'b') {
            aim(&p, &b);
        } else if (cmd == 'c') {
            aim(&p, &c);
        } else if (cmd == '+') {
            bump(p, 10);
        } else if (cmd == '*') {
            *p = *p * 2;
        } else if (cmd == 'S') {
            swap_ptr(&p, &r);
        } else {
            printf("a=%d b=%d c=%d p=%d r=%d\n", a, b, c, peek(p), peek(r));
        }
    }
    return 0;
}
