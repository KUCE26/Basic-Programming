#include <stdio.h>

int main(void) {
    int arr[8], n, i, j, m, t, cnt = 0, sw;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[m]) m = j;
        }
        sw = 0;
        if (m != i) {
            t = arr[i];
            arr[i] = arr[m];
            arr[m] = t;
            cnt++;
            sw = 1;
        }
        printf("%d단계: ", i + 1);
        for (j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", arr[j]);
        }
        printf(sw ? " (교환)\n" : " (유지)\n");
    }
    printf("교환 횟수: %d\n", cnt);
    return 0;
}
