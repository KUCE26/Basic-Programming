#include <stdio.h>

#define PER_DAY 4
#define PRICE 700
#define DAYS 365
#define YEARS 20

int main(void) {
    printf("엘리스 토끼가 지금까지 먹은 당근값은 %d원입니다.\n", PER_DAY * PRICE * DAYS * YEARS);
    return 0;
}
