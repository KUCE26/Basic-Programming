#include <stdio.h>

int main(void) {
    char str[10];

    fgets(str, 10, stdin);
    fputs(str, stdout);
    puts(str);
    printf("끝\n");
    return 0;
}
