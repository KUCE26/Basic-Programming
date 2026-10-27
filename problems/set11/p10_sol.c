#include <stdio.h>

int main(void) {
    int a, b, c, max, mid, prod;

    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >= c) {
        max = a;
        if (b >= c) {
            mid = b;
        } else {
            mid = c;
        }
    } else if (b >= a && b >= c) {
        max = b;
        if (a >= c) {
            mid = a;
        } else {
            mid = c;
        }
    } else {
        max = c;
        if (a >= b) {
            mid = a;
        } else {
            mid = b;
        }
    }
    printf("최댓값: %d\n", max);
    printf("중앙값: %d\n", mid);
    prod = a * b * c;
    if (prod) {
        printf("0 없음\n");
    } else {
        printf("0 포함\n");
    }
    return 0;
}
