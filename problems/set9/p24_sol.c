#include <stdio.h>

int main(void) {
    int a, b, c, i, j;

    scanf("%d %d %d", &a, &b, &c);
    for (i = a; i <= b; i++) {
        if (i > a) {
            printf("\n");
        }
        for (j = 1; j <= c; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }
    return 0;
}
