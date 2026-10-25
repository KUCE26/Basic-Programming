#include <stdio.h>

int main(void) {
    char name[6];

    fgets(name, 6, stdin);
    puts(name);
    printf("끝\n");
    return 0;
}
