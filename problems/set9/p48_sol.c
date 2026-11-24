#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int maxOf(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int a, b;
    int (*fp)(int, int);
    scanf("%d %d", &a, &b);
    fp = add;
    printf("더한 값 : %d\n", fp(a, b));
    fp = mul;
    printf("곱한 값 : %d\n", fp(a, b));
    fp = maxOf;
    printf("큰 값 : %d\n", fp(a, b));
    return 0;
}
