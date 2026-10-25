#include <stdio.h>

int main(void) {
    char name[11];
    int price, qty, total;

    scanf("%s %d %d", name, &price, &qty);
    total = price * qty;
    printf("%-10s|%6d|%3d|%8d\n", name, price, qty, total);
    printf("------------------------------\n");
    return 0;
}
