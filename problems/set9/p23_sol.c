#include <stdio.h>

int main(void) {
    int n, i, sum = 0, last = 0;

    scanf("%d", &n);
    for (i = 1; ; i++) {
        if (i % 5 == 0) {
            continue;
        }
        sum += i;
        last = i;
        if (sum > n) {
            break;
        }
    }
    printf("마지막 번호: %d\n", last);
    printf("합계: %d\n", sum);
    return 0;
}
