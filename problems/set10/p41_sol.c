#include <stdio.h>

int hms(int total, int *h, int *m, int *s) {
    *h = total / 3600;
    *m = total % 3600 / 60;
    *s = total % 60;
    return *h >= 1;
}

int main(void) {
    int n, i, t, h, m, s;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        int big = hms(t, &h, &m, &s);
        printf("%d시간 %d분 %d초", h, m, s);
        if (big == 1) {
            printf(" (장시간)");
        }
        printf("\n");
    }
    return 0;
}
