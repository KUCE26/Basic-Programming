#include <stdio.h>

int main(void) {
    int y;
    scanf("%d", &y);

    int step1 = y * 80;
    double step2 = (double)step1 / 12;
    double step3 = step2 + 1500;
    double answer = step3 - 3917;

    printf("체셔가 생각한 수는 %.2f입니다.\n", answer);
    return 0;
}
