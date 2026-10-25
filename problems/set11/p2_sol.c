#include <stdio.h>

#define PRICE 12000

int main(void) {
    char seat;
    int row, count;

    scanf("%c%dx%d", &seat, &row, &count);

    printf("열 번호: %d\n", seat - 'A' + 1);
    printf("줄 번호: %d\n", row);
    printf("총 금액: %d원\n", count * PRICE);
    return 0;
}
