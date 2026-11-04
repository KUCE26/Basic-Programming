#include <stdio.h>

int main(void) {
    int x, count = 0, max = 0, maxCount = 0, even = 0, emergency = 0;

    while (1) {
        scanf("%d", &x);
        if (x == 0) {
            break;
        }
        if (x == 999) {
            emergency = 1;
            break;
        }
        count++;
        if (count == 1 || x > max) {
            max = x;
            maxCount = 1;
        } else if (x == max) {
            maxCount++;
        }
        if (x % 2 == 0) {
            even++;
        }
    }
    printf(emergency ? "종료: 긴급 정지\n" : "종료: 정상\n");
    if (count == 0) {
        printf("기록 없음\n");
    } else {
        printf("개수: %d\n", count);
        printf("최대: [%4d] (%d번)\n", max, maxCount);
        printf("짝수: %d\n", even);
    }
    return 0;
}
