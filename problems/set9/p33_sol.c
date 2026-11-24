#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101];
    int n, i, j;
    scanf("%s", s);
    n = strlen(s);
    for (i = n - 1; i >= 0; i--) {
        for (j = i; j < n; j++) printf("%c", s[j]);
        printf("\n");
    }
    return 0;
}
