#include <stdio.h>

int stock;

void harvest(int n);
void use(int n);

int main(void) {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    stock = a;
    printf("처음 재고: %d개\n", stock);
    harvest(b);
    use(c);
    printf("남은 재고: %d개\n", stock);
    return 0;
}

void harvest(int n) {
    stock += n;
    printf("수확 후: %d개\n", stock);
}

void use(int n) {
    if (stock >= n) {
        stock -= n;
        printf("사용 후: %d개\n", stock);
    } else {
        printf("재고가 부족합니다.\n");
    }
}
