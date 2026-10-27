#include <stdio.h>

int main(void) {
    int level, coin = 0, box = 0;

    scanf("%d", &level);
    switch (level) {
    case 5:
        coin += 500;
    case 4:
        coin += 200;
        box++;
    case 3:
        coin += 100;
    case 2:
        coin += 50;
        box++;
    case 1:
        coin += 10;
        break;
    default:
        printf("레벨은 1부터 5까지입니다.\n");
        return 0;
    }
    printf("획득 코인: %d\n", coin);
    printf("획득 상자: %d개\n", box);
    return 0;
}
