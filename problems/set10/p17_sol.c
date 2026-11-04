#include <stdio.h>

int main(void) {
    int n, i, score, sum = 0, pass = 0, best = -1;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &score);
        sum += score;
        if (score >= 60) {
            pass++;
        }
        if (score > best) {
            best = score;
        }
    }
    printf("합격: %d명\n", pass);
    printf("최고점: %d\n", best);
    printf("평균: [%7.2f]\n", (double)sum / n);
    return 0;
}
