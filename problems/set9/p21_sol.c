#include <stdio.h>

int main(void) {
    int carrot, sum = 0, count = 0;

    while (1) {
        scanf("%d", &carrot);
        if (carrot < 0) {
            break;
        }
        sum += carrot;
        count++;
    }
    printf("참가한 친구: %d명\n", count);
    printf("당근 총합: %d개\n", sum);
    return 0;
}
