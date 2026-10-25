#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    printf("10진수: %d\n", n);
    printf("8진수: %o\n", n);
    printf("16진수(소문자): %x\n", n);
    printf("16진수(대문자): %X\n", n);
    printf("접두사 포함: %#x\n", n);
    return 0;
}
