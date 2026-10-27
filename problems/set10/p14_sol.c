#include <stdio.h>

int main(void) {
    int x, abs_x;

    scanf("%d", &x);
    abs_x = x < 0 ? -x : x;
    printf("입력한 수: %d\n", x);
    printf("절댓값: %d\n", abs_x);
    if (x == 0) {
        printf("분류: 영\n");
    } else {
        if (x > 0) {
            printf("분류: 양의 %s\n", x % 2 == 0 ? "짝수" : "홀수");
        } else {
            printf("분류: 음의 %s\n", x % 2 == 0 ? "짝수" : "홀수");
        }
    }
    return 0;
}
