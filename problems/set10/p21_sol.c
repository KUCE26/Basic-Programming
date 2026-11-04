#include <stdio.h>

int main(void) {
    int n, i, j, count = 0;
    char ch;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%2d:", i);
        for (j = 1; j <= n; j++) {
            ch = ((i + j) % 2 == 0) ? '#' : '.';
            if (ch == '#') {
                count++;
            }
            printf(" %c", ch);
        }
        printf("\n");
    }
    printf("# 개수: %d\n", count);
    return 0;
}
