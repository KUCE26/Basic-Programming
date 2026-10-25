#include <stdio.h>

int main(void) {
    char c1, c2, c3, c4;

    c1 = getchar();
    c2 = getchar();
    c3 = getchar();
    c4 = getchar();

    putchar((c1 - 'a' + 3) % 26 + 'a');
    putchar((c2 - 'a' + 3) % 26 + 'a');
    putchar((c3 - 'a' + 3) % 26 + 'a');
    putchar((c4 - 'a' + 3) % 26 + 'a');
    putchar('\n');
    return 0;
}
