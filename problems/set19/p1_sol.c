#include <stdio.h>

void magic(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(void) {
    int v[3], q, k, i, j;
    scanf("%d %d %d", &v[0], &v[1], &v[2]);
    scanf("%d", &q);
    for (k = 1; k <= q; k++) {
        scanf("%d %d", &i, &j);
        magic(&v[i], &v[j]);
        printf("%d번: %d %d %d\n", k, v[0], v[1], v[2]);
    }
    return 0;
}
