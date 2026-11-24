#include <stdio.h>

int main(void) {
    int mine[8][8] = {0};
    int r, c, k, i, j, x, y, di, dj, cnt = 0;
    scanf("%d %d %d", &r, &c, &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        mine[y - 1][x - 1] = 1;
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (mine[i][j]) {
                printf("*");
                cnt++;
            } else {
                int near = 0;
                for (di = -1; di <= 1; di++)
                    for (dj = -1; dj <= 1; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c && mine[ni][nj]) near++;
                    }
                printf("%d", near);
            }
        }
        printf("\n");
    }
    printf("지뢰: %d개\n", cnt);
    return 0;
}
