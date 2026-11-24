#include <stdio.h>

int main(void) {
    int hour, minute;
    scanf("%d %d", &hour, &minute);
    int *ph = &hour;
    int *pm = &minute;
    *pm += 15;
    if (*pm >= 60) {
        *pm -= 60;
        *ph += 1;
        if (*ph == 24) {
            *ph = 0;
        }
    }
    printf("시각 %02d:%02d\n", hour, minute);
    return 0;
}
