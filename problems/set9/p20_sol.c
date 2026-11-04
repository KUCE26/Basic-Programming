#include <stdio.h>

int main(void) {
    int x, cnt = 0, sum = 0;

    do {
        scanf("%d", &x);
        if (x != 0) {
            cnt++;
            sum += x;
        }
    } while (x != 0);
    printf("개수: %d\n", cnt);
    printf("총합: %d\n", sum);
    return 0;
}
