#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int *ptr = &a;
    printf("%d %d\n", *ptr, b);
    if (*ptr == b) {
        printf("값이 같아요.\n");
    } else {
        printf("값이 달라요.\n");
    }
    *ptr = b;
    printf("a: %d\n", a);
    return 0;
}
