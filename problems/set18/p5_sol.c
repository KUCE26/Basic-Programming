#include <stdio.h>

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int half(int x) {
    return x / 2;
}

void apply(int arr[], int n, int (*op)(int)) {
    int *p;
    for (p = arr; p < arr + n; p++) *p = op(*p);
}

int main(void) {
    int arr[10], n, i, sum = 0, mode;
    int (*ops[3])(int) = {square, negate, half};
    scanf("%d", &mode);
    if (mode < 1 || mode > 3) {
        printf("잘못된 선택입니다.\n");
        return 0;
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    apply(arr, n, ops[mode - 1]);
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
        sum += arr[i];
    }
    printf("\n합계: %d\n", sum);
    return 0;
}
