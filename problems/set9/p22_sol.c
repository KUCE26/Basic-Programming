#include <stdio.h>

int main(void) {
    int a, b, n, i, count = 0;

    scanf("%d %d %d", &a, &b, &n);
    for (i = 1; i <= n; i++) {
        if (i % a != 0 || i % b != 0) {
            continue;
        }
        printf("%d\n", i);
        count++;
    }
    printf("공배수: %d개\n", count);
    return 0;
}
