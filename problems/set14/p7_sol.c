#include <stdio.h>
#include <string.h>

char a[101], b[101];

void lower(void) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] + ('a' - 'A');
    }
}

void reverse(void) {
    int n = strlen(a), i;
    for (i = 0; i < n; i++) b[i] = a[n - 1 - i];
    b[n] = '\0';
}

int main(void) {
    scanf("%s", a);
    lower();
    reverse();
    printf("%s\n%s\n", a, b);
    if (strcmp(a, b) == 0) printf("회문입니다\n");
    else printf("회문이 아닙니다\n");
    return 0;
}
