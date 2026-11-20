#include <stdio.h>

int main(void) {
    int c_cake = 1;
    int c_soup = 1;
    int c_milk = 2;
    if (c_cake == 1 && c_soup == 1) {
        c_milk = 10;
    }
    printf("당근 우유를 %d개 샀습니다.\n", c_milk);
    return 0;
}
