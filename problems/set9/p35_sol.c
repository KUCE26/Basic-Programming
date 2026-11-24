#include <stdio.h>
#include <string.h>

int main(void) {
    char pw[] = "wonderland";
    char t[51];
    int i, ok = 0;
    for (i = 1; i <= 3; i++) {
        scanf("%s", t);
        if (strcmp(t, pw) == 0) {
            printf("%d번째 시도: 성공\n", i);
            ok = 1;
            break;
        }
        printf("%d번째 시도: 실패\n", i);
    }
    if (!ok) printf("문이 영원히 잠겼습니다\n");
    return 0;
}
