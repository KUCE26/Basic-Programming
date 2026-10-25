#include <stdio.h>

int main(void) {
    char lower, upper;

    scanf("%c", &lower);
    upper = lower - 32;
    printf("대문자: %c\n", upper);
    printf("아스키 코드 차이: %d\n", lower - upper);
    return 0;
}
