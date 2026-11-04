#include <stdio.h>

int main(void) {
    int n, t, d, digits = 0, sum = 0, mx = 0, rev = 0;

    scanf("%d", &n);
    t = n;
    do {
        d = t % 10;
        digits++;
        sum += d;
        if (d > mx) {
            mx = d;
        }
        rev = rev * 10 + d;
        t /= 10;
    } while (t > 0);
    printf("자릿수: %d\n", digits);
    printf("자릿수의 합: %d\n", sum);
    printf("가장 큰 자릿수: %d\n", mx);
    printf("뒤집은 수: %d\n", rev);
    if (rev == n) {
        printf("회문\n");
    } else {
        printf("회문 아님\n");
    }
    return 0;
}
