#include <stdio.h>

int is_leap(int y);
int days_in_month(int y, int m);

int main(void) {
    int y, m, i, total = 0;

    scanf("%d %d", &y, &m);
    printf("%d년 %d월: %d일\n", y, m, days_in_month(y, m));
    if (is_leap(y)) {
        printf("윤년입니다.\n");
    } else {
        printf("평년입니다.\n");
    }
    for (i = 1; i <= m; i++) {
        total += days_in_month(y, i);
    }
    printf("1월부터 %d월까지 누적: %d일\n", m, total);
    return 0;
}

int is_leap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return 1;
    }
    return 0;
}

int days_in_month(int y, int m) {
    switch (m) {
    case 2:
        if (is_leap(y)) {
            return 29;
        }
        return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}
