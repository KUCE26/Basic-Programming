#include <stdio.h>

int main(void) {
    int n, i, count = 0;
    double v, sum = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lf", &v);
        if (v < 0) {
            continue;
        }
        count++;
        sum += v;
        printf("%d번: [%6.1f]\n", i, v);
    }
    printf("유효 %d개, 평균 %.2f\n", count, sum / count);
    return 0;
}
