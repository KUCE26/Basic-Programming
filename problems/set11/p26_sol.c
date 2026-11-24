#include <stdio.h>
#include <stdlib.h>

int byValue(int a, int b) {
    return (a > b) - (a < b);
}

int byAbsDesc(int a, int b) {
    int x = abs(a), y = abs(b);
    if (x != y) return x < y ? 1 : -1;
    return byValue(a, b);
}

static int digitSum(int v) {
    int s = 0;
    v = abs(v);
    while (v > 0) {
        s += v % 10;
        v /= 10;
    }
    return s;
}

int byDigitSum(int a, int b) {
    int x = digitSum(a), y = digitSum(b);
    if (x != y) return x > y ? 1 : -1;
    return byValue(a, b);
}

void sortBy(int *arr, int n, int (*cmp)(int, int)) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (cmp(*(arr + j), *(arr + j + 1)) > 0) {
                t = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = t;
            }
        }
    }
}

int main(void) {
    int arr[15], n, i, mode;
    int (*rules[3])(int, int) = {byValue, byAbsDesc, byDigitSum};
    scanf("%d", &mode);
    if (mode < 1 || mode > 3) {
        printf("잘못된 선택입니다.\n");
        return 0;
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    sortBy(arr, n, rules[mode - 1]);
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n끝과 처음의 차: %d\n", *(arr + n - 1) - *arr);
    return 0;
}
