#include <stdio.h>

int score[30];
int n;

int count_at_least_avg(void) {
    int i, sum = 0, cnt = 0;
    for (i = 0; i < n; i++) sum += score[i];
    for (i = 0; i < n; i++)
        if (score[i] * n >= sum) cnt++;
    return cnt;
}

int main(void) {
    int i, max;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &score[i]);
    max = score[0];
    for (i = 1; i < n; i++)
        if (score[i] > max) max = score[i];
    printf("최고점: %d\n", max);
    printf("위치:");
    for (i = 0; i < n; i++)
        if (score[i] == max) printf(" %d", i + 1);
    printf("\n평균 이상: %d명\n", count_at_least_avg());
    return 0;
}
