#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    printf("후위: %d\n", n++);
    printf("이후: %d\n", n);
    printf("전위: %d\n", ++n);
    printf("이후: %d\n", n);

    int m = n-- * 2;
    printf("m: %d, n: %d\n", m, n);
    return 0;
}
