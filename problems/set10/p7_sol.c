#include <stdio.h>

int main(void) {
    int a, b, c, sum, avg_int;
    double avg_real;

    scanf("%d %d %d", &a, &b, &c);
    sum = a + b + c;
    avg_int = sum / 3;
    avg_real = (double)sum / 3;
    printf("합계: %d\n", sum);
    printf("정수 평균: %d\n", avg_int);
    printf("실수 평균: %.2f\n", avg_real);
    return 0;
}
