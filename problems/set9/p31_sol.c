#include <stdio.h>

int main(void) {
    int a[100], path[100];
    int n, i, pos = 0, jumps = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    while (pos < n) {
        path[jumps] = pos + 1;
        pos += a[pos];
        jumps++;
    }
    printf("점프 횟수: %d\n", jumps);
    for (i = 0; i < jumps; i++) {
        if (i > 0) printf(" ");
        printf("%d", path[i]);
    }
    printf("\n");
    return 0;
}
