#include <stdio.h>

int main(void) {
    int n, hundreds, tens, ones;

    scanf("%d", &n);
    hundreds = n / 100;
    tens = n / 10 % 10;
    ones = n % 10;
    printf("백의 자리: %d\n", hundreds);
    printf("십의 자리: %d\n", tens);
    printf("일의 자리: %d\n", ones);
    printf("자릿수 합: %d\n", hundreds + tens + ones);
    return 0;
}
