#include <stdio.h>
#include <ctype.h>

int countUpper(const char *str) {
    int c = 0;
    while (*str) {
        if (isupper((unsigned char)*str)) c++;
        str++;
    }
    return c;
}

int countDigit(const char *str) {
    int c = 0;
    while (*str) {
        if (isdigit((unsigned char)*str)) c++;
        str++;
    }
    return c;
}

int main(void) {
    char line[105] = "";
    if (fgets(line, sizeof(line), stdin) == NULL) line[0] = '\0';
    printf("대문자의 개수: %d\n", countUpper(line));
    printf("숫자의 개수: %d\n", countDigit(line));
    return 0;
}
