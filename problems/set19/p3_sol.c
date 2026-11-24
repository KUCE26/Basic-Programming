#include <stdio.h>

double asDouble(void *vp, char type) {
    if (type == 'i') return (double)*(int *)vp;
    return *(double *)vp;
}

int main(void) {
    int ints[20];
    double dbls[20];
    void *items[20];
    char types[20];
    int n, i, best = 0;
    double sum = 0.0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &types[i]);
        if (types[i] == 'i') {
            scanf("%d", &ints[i]);
            items[i] = &ints[i];
        } else {
            scanf("%lf", &dbls[i]);
            items[i] = &dbls[i];
        }
        sum += asDouble(items[i], types[i]);
    }
    for (i = 1; i < n; i++) {
        if (asDouble(items[i], types[i]) > asDouble(items[best], types[best])) best = i;
    }
    if (types[best] == 'i') printf("최고 점수: %d (%d번째)\n", *(int *)items[best], best + 1);
    else printf("최고 점수: %.1f (%d번째)\n", *(double *)items[best], best + 1);
    printf("전체 합: %.1f\n", sum);
    return 0;
}
