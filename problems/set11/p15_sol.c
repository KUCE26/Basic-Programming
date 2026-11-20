#include <stdio.h>

int level = 1;

int get_level(void);
void raise_level(int n);
int upgrade(int level);
void show(int level);

int main(void) {
    int a, b, c;
    int level;

    scanf("%d %d %d", &a, &b, &c);
    raise_level(a);
    printf("upgrade(b) = %d\n", upgrade(b));
    show(c);
    level = a + b;
    printf("main 지역 level = %d\n", level);
    raise_level(level);
    printf("최종 전역 level = %d\n", get_level());
    return 0;
}

int get_level(void) {
    return level;
}

void raise_level(int n) {
    level += n;
}

int upgrade(int level) {
    level = level * 2 + 1;
    return level;
}

void show(int level) {
    printf("인자 %d, 전역 %d\n", level, get_level());
}
