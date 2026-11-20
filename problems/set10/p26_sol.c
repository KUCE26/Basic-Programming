#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main(void) {
    int n, i, a, b, sum = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        printf("[%d] %d와 %d: 최대공약수 %3d, 최소공배수 %5d\n", i, a, b, gcd(a, b), lcm(a, b));
        sum += gcd(a, b);
    }
    printf("최대공약수의 합: %d\n", sum);
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
