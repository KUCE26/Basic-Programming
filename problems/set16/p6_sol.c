#include <stdio.h>

int main(void) {
    int i, k, lead, gap;
    scanf("%d", &i);
    printf("*");
    for (k = 0; k < i; k++) printf(" ");
    printf("*");
    for (k = 0; k < i; k++) printf(" ");
    printf("*\n");
    lead = (i + 2) / 2;
    gap = (i % 2 == 0) ? i - 1 : i;
    for (k = 0; k < lead; k++) printf(" ");
    printf("*");
    for (k = 0; k < gap; k++) printf(" ");
    printf("*\n");
    return 0;
}
