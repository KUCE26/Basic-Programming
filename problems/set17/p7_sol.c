#include <stdio.h>

int main(void) {
    int a;
    double b;
    void *vp;
    scanf("%d %lf", &a, &b);
    vp = &a;
    *(int *)vp = *(int *)vp * 2;
    printf("a : %d\n", *(int *)vp);
    vp = &b;
    *(double *)vp = *(double *)vp + 0.5;
    printf("b : %.2f\n", *(double *)vp);
    return 0;
}
