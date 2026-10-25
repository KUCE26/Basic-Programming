#include <stdio.h>

#define PI 3.14159

int main(void) {
    const int TWO = 2;
    double r;

    scanf("%lf", &r);
    printf("둘레: %.2f\n", TWO * PI * r);
    printf("넓이: %.2f\n", PI * r * r);
    return 0;
}
