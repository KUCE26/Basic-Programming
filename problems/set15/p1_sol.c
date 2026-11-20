#include <stdio.h>

int main(void) {
    int a[11], visited[11] = {0};
    int n, i, p = 1, jumps = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    visited[1] = 1;
    while (1) {
        p += a[p];
        jumps++;
        if (p > n) { printf("건넘 %d\n", jumps); break; }
        if (p < 1) { printf("추락 %d\n", jumps); break; }
        if (visited[p]) { printf("갇힘 %d\n", jumps); break; }
        visited[p] = 1;
    }
    return 0;
}
