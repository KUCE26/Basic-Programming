#include <stdio.h>

int digit_sum(int n);
void print_reverse(int n);

int main(void) {
    int n, count = 0;

    scanf("%d", &n);
    while (n != -1) {
        printf("%d: 자릿수 합 %d, 뒤집기 ", n, digit_sum(n));
        print_reverse(n);
        printf("\n");
        count++;
        scanf("%d", &n);
    }
    printf("총 %d개\n", count);
    return 0;
}

int digit_sum(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + digit_sum(n / 10);
}

void print_reverse(int n) {
    if (n < 10) {
        printf("%d", n);
        return;
    }
    printf("%d", n % 10);
    print_reverse(n / 10);
}
