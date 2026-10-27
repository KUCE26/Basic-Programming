#include <stdio.h>

int main(void) {
    double height;

    scanf("%lf", &height);
    if (height >= 120.0) {
        printf("탑승할 수 있어요!\n");
    }
    if (height < 120.0) {
        printf("키가 조금 더 커야 해요.\n");
    }
    return 0;
}
