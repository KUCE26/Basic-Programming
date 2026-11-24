#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x < y) - (x > y);
}

int main(void) {
    int orig[15], sorted[15], n, k, i, cnt = 0, val = 0, found = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &orig[i]);
        sorted[i] = orig[i];
    }
    qsort(sorted, n, sizeof(sorted[0]), cmp);
    for (i = 0; i < n; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            cnt++;
            if (cnt == k) {
                val = sorted[i];
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("%d번째: 없음\n", k);
        return 0;
    }
    printf("%d번째: %d\n", k, val);
    for (i = 0; i < n; i++) {
        if (orig[i] == val) {
            printf("처음 위치: %d\n", i);
            break;
        }
    }
    return 0;
}
