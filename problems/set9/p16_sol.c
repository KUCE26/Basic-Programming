#include <stdio.h>

int main(void) {
    char ride;

    scanf(" %c", &ride);
    switch (ride) {
    case 'r':
        printf("롤러코스터 대기 시간은 40분입니다.\n");
        break;
    case 'c':
        printf("회전목마 대기 시간은 10분입니다.\n");
        break;
    case 'f':
        printf("관람차 대기 시간은 25분입니다.\n");
        break;
    case 'b':
        printf("범퍼카 대기 시간은 15분입니다.\n");
        break;
    default:
        printf("그런 놀이기구는 없습니다.\n");
    }
    return 0;
}
