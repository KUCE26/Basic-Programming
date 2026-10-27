#include <stdio.h>

int main(void) {
    int minutes, fee;
    char member;
    double pay;

    scanf("%d %c", &minutes, &member);
    if (minutes <= 30) {
        fee = 0;
    } else {
        fee = (minutes - 30 + 9) / 10 * 500;
    }
    if (fee > 15000) {
        fee = 15000;
    }
    if (member == 'Y') {
        pay = fee * 0.8;
    } else {
        pay = fee;
    }
    printf("이용 시간: [%5d]분\n", minutes);
    printf("주차 요금: [%8d]원\n", fee);
    printf("결제 금액: [%10.1f]원\n", pay);
    return 0;
}
