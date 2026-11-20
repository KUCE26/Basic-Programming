#include <stdio.h>

int main(void) {
    int n, i, j;
    int snail[9][9];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0, k, nx, ny;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            snail[i][j] = 0;
    for (k = 1; k <= n * n; k++) {
        snail[x][y] = k;
        nx = x + dx[d];
        ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || snail[nx][ny] != 0) {
            d = (d + 1) % 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d", snail[i][j]);
        }
        printf("\n");
    }
    return 0;
}
