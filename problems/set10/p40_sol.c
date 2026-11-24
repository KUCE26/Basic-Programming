#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int arr[20], n, i, j, kinds = 0, best = 0, bestCnt = 0, c;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(arr[0]), cmp);
    i = 0;
    while (i < n) {
        j = i;
        while (j < n && arr[j] == arr[i]) j++;
        c = j - i;
        printf("%d: %d개\n", arr[i], c);
        kinds++;
        if (c > bestCnt) {
            bestCnt = c;
            best = arr[i];
        }
        i = j;
    }
    printf("종류 %d가지, 최다 %d\n", kinds, best);
    return 0;
}
