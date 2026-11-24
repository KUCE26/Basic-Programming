#include <stdio.h>

int main(void) {
    int arr[20], n, i, sum = 0;
    int *p = arr, *maxp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", p + i);
    maxp = p;
    for (i = 0; i < n; i++) {
        sum += *(p + i);
        if (*(p + i) > *maxp) maxp = p + i;
    }
    printf("총 수확량: %d\n", sum);
    printf("최대 수확량: %d (처음부터 %d칸)\n", *maxp, (int)(maxp - p));
    return 0;
}
