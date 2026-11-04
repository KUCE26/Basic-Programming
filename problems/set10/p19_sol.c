#include <stdio.h>

int main(void) {
    int x, cnt = 0, mx, mn;

    scanf("%d", &x);
    mx = x;
    mn = x;
    while (x != -999) {
        cnt++;
        if (x > mx) {
            mx = x;
        }
        if (x < mn) {
            mn = x;
        }
        scanf("%d", &x);
    }
    printf("측정 횟수: %d회\n", cnt);
    printf("최고: [%5d]\n", mx);
    printf("최저: [%5d]\n", mn);
    printf("차이: [%5d]\n", mx - mn);
    return 0;
}
