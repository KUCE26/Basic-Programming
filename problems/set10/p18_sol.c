#include <stdio.h>

int main(void) {
    char c;
    int n, i, vowels = 0;

    scanf(" %c %d", &c, &n);
    for (i = 0; i < n; i++) {
        if (i > 0) {
            putchar(' ');
        }
        putchar(c);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        }
        if (c == 'Z') {
            c = 'A';
        } else {
            c++;
        }
    }
    printf("\n모음 개수: %d\n", vowels);
    return 0;
}
