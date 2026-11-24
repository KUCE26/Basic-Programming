#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int hat1, hat2;
    scanf("%d %d", &hat1, &hat2);
    swap(&hat1, &hat2);
    printf("1번 모자 : %d\n", hat1);
    printf("2번 모자 : %d\n", hat2);
    if (hat1 < hat2) {
        printf("다시 바꿉니다.\n");
        swap(&hat1, &hat2);
    }
    printf("큰 모자 : %d\n", hat1);
    printf("작은 모자 : %d\n", hat2);
    return 0;
}
