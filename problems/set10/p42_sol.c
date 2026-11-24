#include <stdio.h>

void minmax(int arr[], int n, int *mn, int *mx, int *imin, int *imax) {
    int i;
    *mn = arr[0];
    *mx = arr[0];
    *imin = 0;
    *imax = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] < *mn) {
            *mn = arr[i];
            *imin = i;
        }
        if (arr[i] >= *mx) {
            *mx = arr[i];
            *imax = i;
        }
    }
}

int main(void) {
    int arr[20], n, i, mn, mx, imin, imax;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    minmax(arr, n, &mn, &mx, &imin, &imax);
    printf("최솟값: %d (위치 %d)\n", mn, imin);
    printf("최댓값: %d (위치 %d)\n", mx, imax);
    printf("차이: %d\n", mx - mn);
    return 0;
}
