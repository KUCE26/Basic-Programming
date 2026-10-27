#include <stdio.h>

int main(void) {
    int rabbit, cheshire, r;

    scanf("%d %d", &rabbit, &cheshire);
    r = (rabbit - cheshire + 3) % 3;

    printf("토끼: %s / 체셔: %s\n",
           rabbit == 0 ? "가위" : (rabbit == 1 ? "바위" : "보"),
           cheshire == 0 ? "가위" : (cheshire == 1 ? "바위" : "보"));
    printf("결과: %s\n", r == 0 ? "무승부" : (r == 1 ? "토끼 승" : "체셔 승"));
    printf("합: %s\n", (rabbit + cheshire) % 2 == 0 ? "짝수" : "홀수");
    return 0;
}
