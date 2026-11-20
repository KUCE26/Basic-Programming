#include <stdio.h>

int main(void) {
    int g[9][9] = {0};
    int n, i, j, b = 0, d = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        g[0][i] = 1;
        g[n - 1][i] = 1;
        g[i][0] = 1;
        g[i][n - 1] = 1;
    }
    for (i = 0; i < n; i++) {
        g[i][i] = 2;
        g[i][n - 1 - i] = 2;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (g[i][j] == 0) printf(".");
            else if (g[i][j] == 1) { printf("#"); b++; }
            else { printf("*"); d++; }
        }
        printf("\n");
    }
    printf("테두리 칸: %d, 대각선 칸: %d\n", b, d);
    return 0;
}
