#include <stdio.h>

int max3(int a, int b, int c);
int min3(int a, int b, int c);

int main(void) {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("최대: %d\n", max3(a, b, c));
    printf("최소: %d\n", min3(a, b, c));
    printf("차이: %d\n", max3(a, b, c) - min3(a, b, c));
    return 0;
}

int max3(int a, int b, int c) {
    int m = a;

    if (b > m) {
        m = b;
    }
    if (c > m) {
        m = c;
    }
    return m;
}

int min3(int a, int b, int c) {
    int m = a;

    if (b < m) {
        m = b;
    }
    if (c < m) {
        m = c;
    }
    return m;
}
