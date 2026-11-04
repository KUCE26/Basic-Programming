#include <stdio.h>

int main(void) {
    int n, i;

    scanf("%d", &n);
    for (i = n; i >= 1; i -= 2) {
        printf("현재 숫자: %d\n", i);
    }
    printf("발사!\n");
    return 0;
}
