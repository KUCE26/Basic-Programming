#include <stdio.h>

int main(void) {
    char s[100];
    int i, up = 0, low = 0;
    fgets(s, 100, stdin);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            up++;
            printf("%c", s[i] + ('a' - 'A'));
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            low++;
            printf("%c", s[i] - ('a' - 'A'));
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n대문자 %d개, 소문자 %d개\n", up, low);
    return 0;
}
