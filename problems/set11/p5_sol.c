#include <stdio.h>

int main(void) {
    char c1, c2, c3, c4;

    c1 = getchar();
    c2 = getchar();
    c3 = getchar();
    c4 = getchar();

    putchar(c1 + 3);
    putchar(c2 + 3);
    putchar(c3 + 3);
    putchar(c4 + 3);
    putchar('\n');
    return 0;
}
