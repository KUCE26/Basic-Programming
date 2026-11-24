#include <stdio.h>
#include <ctype.h>

int wordCount(const char *s) {
    int c = 0;
    while (*s) {
        if (isalpha((unsigned char)*s)) {
            c++;
            while (isalpha((unsigned char)*s)) s++;
        } else {
            s++;
        }
    }
    return c;
}

const char *longestWord(const char *s, int *len) {
    const char *best = NULL;
    int bl = 0;
    while (*s) {
        if (isalpha((unsigned char)*s)) {
            const char *st = s;
            while (isalpha((unsigned char)*s)) s++;
            if (s - st > bl) {
                bl = (int)(s - st);
                best = st;
            }
        } else {
            s++;
        }
    }
    *len = bl;
    return best;
}

int main(void) {
    char line[210] = "";
    int len, i;
    const char *w;
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    w = longestWord(line, &len);
    if (w == NULL) {
        printf("단어 없음\n");
        return 0;
    }
    printf("단어 수: %d\n", wordCount(line));
    printf("가장 긴 단어: ");
    for (i = 0; i < len; i++) putchar(w[i]);
    printf(" (길이 %d, 위치 %d)\n", len, (int)(w - line));
    return 0;
}
