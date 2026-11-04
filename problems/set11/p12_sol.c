#include <stdio.h>

int main(void) {
    int n, i;
    double all = 0.0, skip = 0.0, term;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        term = 1.0 / i;
        if (i % 2 == 0) {
            term = -term;
        }
        all += term;
        if (i % 3 != 0) {
            skip += term;
        }
    }
    printf("전체 합: %.5f\n", all);
    printf("3의 배수 항 제외: %.5f\n", skip);
    printf("마지막 항: %c1/%d\n", (n % 2 == 1) ? '+' : '-', n);
    return 0;
}
