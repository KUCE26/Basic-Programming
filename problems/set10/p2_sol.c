#include <stdio.h>

int main(void) {
    double celsius, fahrenheit, kelvin;

    scanf("%lf", &celsius);
    fahrenheit = celsius * 9.0 / 5 + 32;
    kelvin = celsius + 273.15;
    printf("화씨: %.1f\n", fahrenheit);
    printf("켈빈: %8.2f\n", kelvin);
    return 0;
}
