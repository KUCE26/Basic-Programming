#include <stdio.h>

int main(void) {
    char s[101], c;
    int i, cnt = 0, first = -1;
    scanf("%s %c", s, &c);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            cnt++;
            if (first == -1) first = i;
        }
    }
    printf("개수: %d\n처음 위치: %d\n", cnt, first);
    return 0;
}
