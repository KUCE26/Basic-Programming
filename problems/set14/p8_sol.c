#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101];
    int k, i;
    fgets(s, 101, stdin);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }
    scanf("%d", &k);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = 'A' + (s[i] - 'A' + k) % 26;
        else if (s[i] >= 'a' && s[i] <= 'z') s[i] = 'a' + (s[i] - 'a' + k) % 26;
    }
    printf("%s\n암호문 길이: %d\n", s, (int)strlen(s));
    return 0;
}
