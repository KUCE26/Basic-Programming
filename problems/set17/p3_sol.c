#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
    int *ptr1 = &num;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    printf("%d %d %d\n", ***ptr3, **ptr2, *ptr1);
    ***ptr3 = ***ptr3 - 7;
    printf("%d %d %d\n", *ptr1, **ptr2, ***ptr3);
    printf("num: %d\n", num);
    return 0;
}
