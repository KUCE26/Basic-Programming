#include <stdio.h>

int main(void) {
    int dan, last, i, sum = 0;

    scanf("%d %d", &dan, &last);
    for (i = 1; i <= last; i++) {
        printf("%d x %d = %d\n", dan, i, dan * i);
        sum += dan * i;
    }
    printf("합계: %d\n", sum);
    return 0;
}
