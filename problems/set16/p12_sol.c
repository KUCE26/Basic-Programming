#include <stdio.h>

int countWords(char str[]) {
    int i, count = 0, inWord = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

int main(void) {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    printf("입력한 문장의 단어 개수: %d\n", countWords(input));
    return 0;
}
