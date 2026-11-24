#include <stdio.h>

void swap_ptr(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    int *p = &x;
    int *q = &y;
    if (*p < *q) {
        swap_ptr(&p, &q);
    }
    printf("큰 쪽: %d\n", *p);
    printf("작은 쪽: %d\n", *q);
    *p += 10;
    printf("x=%d y=%d\n", x, y);
    if (p == &x) {
        printf("p 는 x 를 가리킵니다.\n");
    } else {
        printf("p 는 y 를 가리킵니다.\n");
    }
    return 0;
}
