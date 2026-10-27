#include <stdio.h>

int main(void) {
    double temp, humidity, wind;

    scanf("%lf %lf %lf", &temp, &humidity, &wind);
    printf("기온: [%6.1f]도\n", temp);
    printf("습도: [%6.1f]%%\n", humidity);
    printf("풍속: [%6.1f]m/s\n", wind);
    if (temp >= 15.0 && temp <= 28.0 && wind < 5.0 && (humidity < 80.0 || temp < 20.0)) {
        printf("판정: 캠핑하기 좋은 날!\n");
    } else {
        printf("판정: 캠핑은 다음에...\n");
    }
    return 0;
}
