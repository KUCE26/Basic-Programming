#include <stdio.h>

int main(void) {
    int a, b;
    int small;
    long long big;

    scanf("%d %d", &a, &b);

    small = a * b;
    big = (long long)a * b;

    printf("int 곱: %d\n", small);
    printf("long long 곱: %lld\n", big);
    return 0;
}
