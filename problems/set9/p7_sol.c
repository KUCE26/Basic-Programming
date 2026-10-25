#include <stdio.h>

int main(void) {
    char a, b, c;

    a = getchar();
    b = getchar();
    c = getchar();
    putchar(c);
    putchar(b);
    putchar(a);
    putchar('\n');
    return 0;
}
