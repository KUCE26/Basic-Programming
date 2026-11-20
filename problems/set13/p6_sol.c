#include <stdio.h>
#include <string.h>

int main(void) {
    char a[31], b[31], m[100];
    scanf("%s %s", a, b);
    printf("첫 단어 길이: %d\n", (int)strlen(a));
    printf("둘째 단어 길이: %d\n", (int)strlen(b));
    strcpy(m, a);
    strcat(m, "-");
    strcat(m, b);
    printf("부대 이름: %s\n", m);
    printf("부대 이름 길이: %d\n", (int)strlen(m));
    return 0;
}
