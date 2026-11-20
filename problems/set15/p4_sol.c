#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[8];
    int n, i, nl = 0;
    fgets(buf, 8, stdin);
    n = strlen(buf);
    for (i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n') {
            nl = 1;
            buf[i] = '\0';
            break;
        }
    }
    printf("읽은 글자 수: %d\n", n);
    printf("개행 포함: %s\n", nl ? "예" : "아니오");
    printf("내용: [%s]\n", buf);
    return 0;
}
