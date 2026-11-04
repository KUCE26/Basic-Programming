#include <stdio.h>

int main(void) {
    int num, i = 1, cnt = 0, sum = 0;

    scanf("%d", &num);
    while (i <= num) {
        if (num % i == 0) {
            printf("%d\n", i);
            cnt++;
            sum += i;
        }
        i++;
    }
    printf("개수: %d\n", cnt);
    printf("합: %d\n", sum);
    return 0;
}
