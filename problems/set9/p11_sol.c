#include <stdio.h>

int main(void) {
    double meter, sec;
    scanf("%lf %lf", &meter, &sec);

    double speed = meter / sec * 3.6;
    printf("평균 속도: %.2fkm/h\n", speed);
    return 0;
}
