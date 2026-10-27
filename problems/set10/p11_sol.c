#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int cnt = 0;

    int r1 = (b != 0) && (a / b >= 2);
    int r2 = (b == 0) || (a % b == 0);
    int r3 = (a > b) || (++cnt > 0);
    int r4 = (a >= 100) && (++cnt > 1);

    printf("r1: %d\n", r1);
    printf("r2: %d\n", r2);
    printf("r3: %d\n", r3);
    printf("r4: %d\n", r4);
    printf("cnt: %d\n", cnt);
    return 0;
}
