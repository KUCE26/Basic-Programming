#include <stdio.h>

int main(void) {
    char c;

    scanf("%c", &c);
    printf("아스키: %d\n", c);
    printf("다음 문자: %c\n", c + 1);
    return 0;
}
