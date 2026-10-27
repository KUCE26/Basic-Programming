#include <stdio.h>

int main(void) {
    int total, per;
    scanf("%d %d", &total, &per);

    int full = total / per;
    int rest = total % per;

    printf("가득 찬 상자: %d %s\n", full, full == 1 ? "box" : "boxes");
    printf("남은 사과: %d %s\n", rest, rest == 1 ? "apple" : "apples");
    printf("필요한 상자 수: %d\n", full + (rest > 0));
    return 0;
}
