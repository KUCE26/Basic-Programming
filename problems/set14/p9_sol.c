#include <stdio.h>

int main(void) {
    int arr[8], n, i, j, t, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                cnt++;
            }
        }
        printf("%d회차: ", i + 1);
        for (j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", arr[j]);
        }
        printf("\n");
    }
    printf("교환 횟수: %d\n", cnt);
    return 0;
}
