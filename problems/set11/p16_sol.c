#include <stdio.h>

void to_base(int n, int b);
int count_digits(int n, int b);

int main(void) {
    int n, b, count = 0;

    scanf("%d", &n);
    while (n != -1) {
        scanf("%d", &b);
        printf("%d -> %d진수: ", n, b);
        to_base(n, b);
        printf(" (%d자리)\n", count_digits(n, b));
        count++;
        scanf("%d", &n);
    }
    printf("변환 횟수: %d\n", count);
    return 0;
}

void to_base(int n, int b) {
    if (n < b) {
        printf("%d", n);
        return;
    }
    to_base(n / b, b);
    printf("%d", n % b);
}

int count_digits(int n, int b) {
    if (n < b) {
        return 1;
    }
    return 1 + count_digits(n / b, b);
}
