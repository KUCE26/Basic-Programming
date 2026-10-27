#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("a > b: %d\n", a > b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("둘 다 양수: %d\n", a > 0 && b > 0);
    printf("하나라도 짝수: %d\n", a % 2 == 0 || b % 2 == 0);
    printf("a가 짝수가 아님: %d\n", !(a % 2 == 0));
    return 0;
}
