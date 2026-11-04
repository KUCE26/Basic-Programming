#include <stdio.h>

int main(void) {
    int n, a, b, compare = 0, pairs = 0;

    scanf("%d", &n);
    for (a = 1; ; a++) {
        if (a * a > n) {
            break;
        }
        for (b = a; b <= n; b++) {
            compare++;
            if (a * b > n) {
                break;
            }
            if (a * b == n) {
                printf("%d x %d = %d\n", a, b, n);
                pairs++;
            }
        }
    }
    printf("비교 횟수: %d\n", compare);
    printf("쌍 개수: %d\n", pairs);
    printf(pairs == 1 ? "소수입니다\n" : "소수가 아닙니다\n");
    return 0;
}
