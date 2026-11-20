#include <stdio.h>

float grades[30] = {3.5, 4.0, 3.5, 2.5, 4.5, 1.0, 0.0, 4.5, 3.5, 4.5,
                    1.5, 2.0, 4.5, 3.0, 3.5, 3.5, 3.5, 4.0, 2.0, 1.0,
                    1.0, 3.0, 2.5, 2.0, 2.5, 3.5, 4.0, 4.0, 3.5, 4.5};

int main(void) {
    int i, first = 1;
    float sum = 0, avg;
    for (i = 0; i < 30; i++) sum += grades[i];
    avg = sum / 30;
    for (i = 0; i < 30; i++) {
        if (grades[i] <= avg) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
