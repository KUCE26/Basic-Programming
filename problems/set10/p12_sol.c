#include <stdio.h>

int main(void) {
    int unit, qty, coupon;
    scanf("%d", &unit);
    scanf("%d", &qty);
    scanf("%d", &coupon);

    int pay = unit;
    pay *= qty;
    pay -= coupon;
    printf("상품 합계: %8d원\n", pay);
    printf("쿠폰 할인: -%7d원\n", coupon);

    int ship = pay >= 30000 ? 0 : 3000;
    printf("배송비: %8d원\n", ship);

    pay += ship;
    printf("결제 금액: %8d원\n", pay);

    int point = pay;
    point /= 100;
    printf("적립 포인트: %d점\n", point);

    int small = pay;
    small %= 1000;
    printf("천원 미만: %03d원\n", small);

    printf("개당 평균: %.2f원\n", (double)pay / qty);
    return 0;
}
