#include <stdio.h>

int is_prime(int n);

int main(void) {
    int a, b, i, count = 0;

    scanf("%d %d", &a, &b);
    for (i = a; i <= b; i++) {
        if (is_prime(i)) {
            if (count > 0) {
                printf(" ");
            }
            printf("%d", i);
            count++;
        }
    }
    if (count == 0) {
        printf("없음");
    }
    printf("\n개수: %d\n", count);
    return 0;
}

int is_prime(int n) {
    int i;

    if (n < 2) {
        return 0;
    }
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
