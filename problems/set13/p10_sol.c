#include <stdio.h>

void selectionSortDesc(int arr[], int n) {
    int i, j, m, t;
    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[m]) m = j;
        }
        t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
    }
}

int main(void) {
    int arr[20], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    selectionSortDesc(arr, n);
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("상위 3개 합: %d\n", arr[0] + arr[1] + arr[2]);
    return 0;
}
