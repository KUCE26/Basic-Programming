#include <stdio.h>

int main(void) {
    double a, b, sum;

    scanf("%lf %lf", &a, &b);
    sum = a + b;

    printf("%.0f\n", sum);
    printf("%.1f\n", sum);
    printf("%.3f\n", sum);
    printf("[%10.3f]\n", sum);
    printf("[%-10.3f]\n", sum);
    return 0;
}
