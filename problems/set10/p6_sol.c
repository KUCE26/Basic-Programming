#include <stdio.h>

int main(void) {
    int age;
    double height;
    char blood;

    scanf("%d,%lf,%c", &age, &height, &blood);
    printf("나이: %d살\n", age);
    printf("키: %.1fcm\n", height);
    printf("혈액형: %c형\n", blood);
    return 0;
}
