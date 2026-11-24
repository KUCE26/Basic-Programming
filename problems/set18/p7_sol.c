#include <stdio.h>

int *findFirst(int *begin, int *end, int target) {
    int *p;
    for (p = begin; p < end; p++) {
        if (*p == target) return p;
    }
    return NULL;
}

int main(void) {
    int arr[30], n, i, target, cnt = 0;
    int *q, *first = NULL, *last = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    for (q = findFirst(arr, arr + n, target); q != NULL; q = findFirst(q + 1, arr + n, target)) {
        if (first == NULL) first = q;
        last = q;
        cnt++;
    }
    printf("발견 횟수: %d\n", cnt);
    if (cnt == 0) return 0;
    printf("위치:");
    for (q = findFirst(arr, arr + n, target); q != NULL; q = findFirst(q + 1, arr + n, target)) {
        printf(" %d", (int)(q - arr));
    }
    printf("\n첫 위치와 마지막 위치의 차이: %d\n", (int)(last - first));
    return 0;
}
