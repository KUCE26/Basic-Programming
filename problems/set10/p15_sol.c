#include <stdio.h>

int main(void) {
    int month, days;

    scanf("%d", &month);
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    default:
        days = 28;
    }
    printf("%d월: %d일\n", month, days);
    switch (month) {
    case 3:
    case 4:
    case 5:
        printf("계절: 봄\n");
        break;
    case 6:
    case 7:
    case 8:
        printf("계절: 여름\n");
        break;
    case 9:
    case 10:
    case 11:
        printf("계절: 가을\n");
        break;
    default:
        printf("계절: 겨울\n");
    }
    return 0;
}
