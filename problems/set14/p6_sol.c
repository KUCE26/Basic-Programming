#include <stdio.h>

int main(void) {
    char s[101], c;
    int i, kept = 0, removed = 0;
    scanf("%s", s);
    for (i = 0; s[i] != '\0'; i++) {
        c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            removed++;
        } else {
            if (kept > 0) printf("-");
            printf("%c", c);
            kept++;
        }
    }
    printf("\n남은 글자 %d개, 삭제 %d개\n", kept, removed);
    return 0;
}
