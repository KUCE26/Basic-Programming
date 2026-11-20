#include <stdio.h>

int main(void) {
    int m[5][5];
    int colsum[5] = {0};
    int r, c, i, j, total = 0, best = 0, bestsum = -1;
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &m[i][j]);
    for (i = 0; i < r; i++) {
        int rs = 0;
        for (j = 0; j < c; j++) {
            printf("%4d", m[i][j]);
            rs += m[i][j];
            colsum[j] += m[i][j];
        }
        printf(" |%5d\n", rs);
        total += rs;
        if (rs > bestsum) { bestsum = rs; best = i + 1; }
    }
    for (j = 0; j < c; j++) printf("%4d", colsum[j]);
    printf(" |%5d\n", total);
    printf("합이 가장 큰 행: %d\n", best);
    return 0;
}
