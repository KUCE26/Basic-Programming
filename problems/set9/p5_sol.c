#include <stdio.h>

int main(void) {
    int y, mo, d, h, mi, s;

    scanf("%d-%d-%dT%d:%d:%d", &y, &mo, &d, &h, &mi, &s);
    printf("%d년 %02d월 %02d일 %02d시 %02d분 %02d초\n", y, mo, d, h, mi, s);
    return 0;
}
