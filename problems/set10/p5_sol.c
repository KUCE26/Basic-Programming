#include <stdio.h>

int main(void) {
    char lower, upper;

    scanf("%c", &lower);
    upper = lower - 32;
    printf("대문자: %c\n", upper);
    printf("대문자의 아스키 코드: %d\n", upper);
    return 0;
}
