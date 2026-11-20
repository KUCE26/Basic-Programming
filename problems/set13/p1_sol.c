#include <stdio.h>

int main(void) {
    int s[20];
    int n, i, full = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &s[i]);
    for (i = 0; i < n; i++) {
        s[i] += 5;
        if (s[i] > 100) s[i] = 100;
        if (s[i] == 100) full++;
    }
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", s[i]);
    }
    printf("\n만점자: %d명\n", full);
    return 0;
}
