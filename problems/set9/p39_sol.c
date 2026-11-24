#include <stdio.h>

int findFirst(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main(void) {
    int arr[20], n, key, i, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &key);
    printf("%d\n", findFirst(arr, n, key));
    for (i = 0; i < n; i++) {
        if (arr[i] == key) cnt++;
    }
    printf("등장 횟수: %d회\n", cnt);
    return 0;
}
