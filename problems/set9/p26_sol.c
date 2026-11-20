#include <stdio.h>

void print_line(int space, int star);

int main(void) {
    int n, i;

    scanf("%d", &n);
    for (i = n; i >= 1; i--) {
        print_line(n - i, 2 * i - 1);
    }
    for (i = 2; i <= n; i++) {
        print_line(n - i, 2 * i - 1);
    }
    return 0;
}

void print_line(int space, int star) {
    int i;

    for (i = 0; i < space; i++) {
        printf(" ");
    }
    for (i = 0; i < star; i++) {
        printf("*");
    }
    printf("\n");
}
