#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int arr[15], m = 0, v, i;
    while (1) {
        scanf("%d", &v);
        if (v == 0) break;
        arr[m++] = v;
        qsort(arr, m, sizeof(arr[0]), cmp);
        printf("추가 %d -> ", v);
        for (i = 0; i < m; i++) {
            if (i > 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    if (m == 0) printf("입력 없음\n");
    else printf("최댓값과 최솟값의 차: %d\n", arr[m - 1] - arr[0]);
    return 0;
}
