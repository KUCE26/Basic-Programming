#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int maxOf(int a, int b) {
    return a > b ? a : b;
}

int minOf(int a, int b) {
    return a < b ? a : b;
}

void run(int (*fp)(int, int)) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("결괏값은 : %d\n", fp(a, b));
}

int main(void) {
    int (*ops[5])(int, int) = {add, sub, mul, maxOf, minOf};
    int cmd, cnt = 0;
    while (scanf("%d", &cmd) == 1 && cmd != 0) {
        if (cmd >= 1 && cmd <= 5) {
            run(ops[cmd - 1]);
            cnt++;
        } else {
            printf("없는 메뉴입니다.\n");
        }
    }
    printf("처리한 연산: %d개\n", cnt);
    return 0;
}
