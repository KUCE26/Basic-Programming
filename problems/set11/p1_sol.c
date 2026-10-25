#include <stdio.h>

int main(void) {
    char name[20];
    char title[20];
    char phone[20];

    scanf("%s", name);
    scanf("%s", title);
    scanf("%s", phone);

    printf("+-----------------------+\n");
    printf("| \"Bunny\\Card\"          |\n");
    printf("| Name : %-14s |\n", name);
    printf("| Title: %-14s |\n", title);
    printf("| Tel  : %-14s |\n", phone);
    printf("+-----------------------+\n");
    return 0;
}
