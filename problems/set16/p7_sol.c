#include <stdio.h>

float char2num(char c) {
    if (c == 'A') return 4.0;
    if (c == 'B') return 3.0;
    if (c == 'C') return 2.0;
    if (c == 'D') return 1.0;
    return 0.0;
}

int main(void)
{
    printf("A grade : %.1f\n", char2num('A'));
    printf("B grade : %.1f\n", char2num('B'));
    printf("C grade : %.1f\n", char2num('C'));
    printf("D grade : %.1f\n", char2num('D'));
    printf("F grade : %.1f\n", char2num('F'));
    return 0;
}
