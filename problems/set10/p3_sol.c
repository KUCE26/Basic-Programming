#include <stdio.h>

int main(void) {
    int seconds, hour, minute, second;

    scanf("%d", &seconds);
    hour = seconds / 3600;
    minute = seconds % 3600 / 60;
    second = seconds % 60;
    printf("%02d:%02d:%02d\n", hour, minute, second);
    return 0;
}
