#include <stdio.h>

int main(void) {
    int cnt[10] = {0};
    int n, i, j, x, best = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (i = 0; i < 10; i++) {
        printf("%d:", i);
        for (j = 0; j < cnt[i]; j++) printf(" *");
        printf("\n");
        if (cnt[i] > cnt[best]) best = i;
    }
    printf("최빈값: %d\n", best);
    return 0;
}
