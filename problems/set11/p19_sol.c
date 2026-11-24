#include <stdio.h>
#include <string.h>

int main(void) {
    char w[3][21];
    int i, r, best = 0;
    for (i = 0; i < 3; i++) scanf("%s", w[i]);
    for (i = 0; i < 2; i++) {
        r = strcmp(w[i], w[i + 1]);
        printf("%s %c %s\n", w[i], r < 0 ? '<' : (r > 0 ? '>' : '='), w[i + 1]);
    }
    for (i = 1; i < 3; i++) {
        if (strcmp(w[i], w[best]) < 0) best = i;
    }
    printf("사전 맨 앞: %s\n", w[best]);
    return 0;
}
