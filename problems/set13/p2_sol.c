#include <stdio.h>

int main(void) {
    int a[30];
    int n, i, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (i = n - 1; i >= 0; i--) {
        printf("%d", a[i]);
        if (i > 0) printf(" ");
    }
    printf("\n합계: %d\n", sum);
    return 0;
}
