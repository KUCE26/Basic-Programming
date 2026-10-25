#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("몫: %d\n", a / b);
    printf("나머지: %d\n", a % b);
    printf("실수 나눗셈: %.3f\n", (double)a / b);
    return 0;
}
