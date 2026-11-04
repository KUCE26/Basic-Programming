#include <stdio.h>

int main(void) {
    int n, i, odd = 0, even = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("[%2d] %4d", i, i * i);
        if (i % 2 == 1) {
            printf(" *");
        }
        printf("\n");
        odd += (i % 2 == 1) ? i * i : 0;
        even += (i % 2 == 0) ? i * i : 0;
    }
    printf("홀수 제곱합: %d\n", odd);
    printf("짝수 제곱합: %d\n", even);
    return 0;
}
