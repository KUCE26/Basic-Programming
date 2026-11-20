#include <stdio.h>

int even_sum(int n);

int main(void) {
    int n;

    scanf("%d", &n);
    if (n < 0) {
        printf("0 이상의 수를 입력하세요.\n");
    } else {
        printf("2부터 %d까지 짝수의 합: %d\n", n, even_sum(n));
    }
    return 0;
}

int even_sum(int n) {
    if (n < 2) {
        return 0;
    }
    if (n % 2 == 0) {
        return n + even_sum(n - 2);
    }
    return even_sum(n - 1);
}
