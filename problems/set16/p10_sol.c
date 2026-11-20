#include <stdio.h>

int main(void) {
    int tri[15][15] = {{0}};
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        tri[i][0] = 1;
        tri[i][i] = 1;
        for (j = 1; j < i; j++) {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j > 0) printf(" ");
            printf("%d", tri[i][j]);
        }
        printf("\n");
    }
    return 0;
}
