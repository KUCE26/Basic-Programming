#include <stdio.h>

int main(void) {
    int a, b, c, m;
    scanf("%d %d %d", &a, &b, &c);
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        m = b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        m = a;
    } else {
        m = c;
    }
    printf("중간값은 %d입니다.\n", m);
    return 0;
}
