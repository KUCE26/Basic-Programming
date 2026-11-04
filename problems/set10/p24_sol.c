#include <stdio.h>

int main(void) {
    char c;
    int n, i, j, sum = 0, code;

    scanf(" %c %d", &c, &n);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            if (j > 0) {
                putchar('-');
            }
            code = (i % 2 == 1) ? c + j : c + i - 1 - j;
            putchar(code);
            sum += code;
        }
        putchar('\n');
    }
    printf("아스키 합: %d\n", sum);
    return 0;
}
