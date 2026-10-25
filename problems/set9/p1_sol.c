#include <stdio.h>

int main(void) {
    int age;
    double height;
    char grade;

    scanf("%d", &age);
    scanf("%lf", &height);
    scanf(" %c", &grade);

    printf("=== 토끼 카드 ===\n");
    printf("나이: %d세\n", age);
    printf("키: %.1fcm\n", height);
    printf("등급: %c\n", grade);
    return 0;
}
