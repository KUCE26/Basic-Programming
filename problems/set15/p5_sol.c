#include <stdio.h>

int main(void) {
    int score[10], id[10], n, i, j, t, rank = 0, tie = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &score[i]);
        id[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (score[j] < score[j + 1]) {
                t = score[j]; score[j] = score[j + 1]; score[j + 1] = t;
                t = id[j]; id[j] = id[j + 1]; id[j + 1] = t;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i == 0 || score[i] != score[i - 1]) rank = i + 1;
        printf("%d등: %d번 (%d점)\n", rank, id[i], score[i]);
        if ((i > 0 && score[i] == score[i - 1]) || (i < n - 1 && score[i] == score[i + 1])) tie++;
    }
    printf("공동 순위 선수: %d명\n", tie);
    return 0;
}
