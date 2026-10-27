#include <stdio.h>

int main(void) {
    int flags;
    scanf("%d", &flags);

    int r = flags & 1;
    int w = (flags >> 1) & 1;
    int x = (flags >> 2) & 1;
    int adm = (flags >> 3) & 1;
    int cnt = r + w + x + adm;

    printf("읽기: %d\n", r);
    printf("쓰기: %d\n", w);
    printf("실행: %d\n", x);
    printf("관리: %d\n", adm);
    printf("권한 수: %d\n", cnt);
    printf("등급: %s\n", adm ? "관리자" : w ? "작성자" : r ? "독자" : "없음");
    printf("켜진 비율: %.1f%%\n", (double)cnt / 4 * 100);
    printf("반전: %d\n", ~flags & 15);
    return 0;
}
