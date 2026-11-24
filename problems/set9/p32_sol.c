#include <stdio.h>

int main(void) {
    int board[6][6] = {0};
    int k, i, j, r, c, cnt = 0;
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d", &r, &c);
        board[r - 1][c - 1] = 1;
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (j > 0) printf(" ");
            if (board[i][j] == 1) { printf("O"); cnt++; }
            else printf(".");
        }
        printf("\n");
    }
    printf("돌: %d개\n", cnt);
    return 0;
}
