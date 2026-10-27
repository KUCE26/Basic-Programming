#include <stdio.h>

int main(void) {
    int score;

    scanf("%d", &score);
    if (score >= 90) {
        printf("%d점: 금메달\n", score);
    } else if (score >= 75) {
        printf("%d점: 은메달\n", score);
    } else if (score >= 60) {
        printf("%d점: 동메달\n", score);
    } else {
        printf("%d점: 메달 없음\n", score);
    }
    return 0;
}
