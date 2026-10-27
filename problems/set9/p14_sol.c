#include <stdio.h>
#include <string.h>

int main(void) {
    char word[20];

    scanf("%s", word);
    if (strcmp(word, "carrot") == 0) {
        printf("문이 열립니다!\n");
    } else {
        printf("문이 열리지 않아요.\n");
    }
    return 0;
}
