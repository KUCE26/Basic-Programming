#include <stdio.h>

int main(void) {
    int n, i, k, w, count = 0;
    char border, inner;

    scanf("%d %c %c", &n, &border, &inner);
    for (i = 1; i <= n; i++) {
        for (k = 1; k < i; k++) {
            putchar(' ');
        }
        w = 2 * (n - i) + 1;
        for (k = 1; k <= w; k++) {
            if (i == 1 || k == 1 || k == w) {
                putchar(border);
                count++;
            } else {
                putchar(inner);
            }
        }
        putchar('\n');
    }
    printf("테두리: %d개\n", count);
    return 0;
}
