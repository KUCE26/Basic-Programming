#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int arr[8], n, i, j, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        int changed = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                cnt++;
                changed = 1;
            }
        }
        if (!changed) {
            break;
        }
        printf("패스 %d:", i + 1);
        for (j = 0; j < n; j++) {
            printf(" %d", arr[j]);
        }
        printf("\n");
    }
    printf("교환 횟수: %d\n", cnt);
    return 0;
}
