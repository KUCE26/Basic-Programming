#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main(void) {
    char names[10][20];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%s", names[i]);
    qsort(names, n, sizeof(names[0]), cmp);
    for (i = 0; i < n; i++) printf("%s\n", names[i]);
    printf("가장 앞선 이름: %s\n", names[0]);
    return 0;
}
