#include <stdio.h>

void solve(int arr[], int len) {
    int i, sum = 0;
    double avg;
    for (i = 0; i < len; i++) sum += arr[i];
    avg = (double)sum / len;
    printf("%.1f\n", avg);
    int first = 1;
    for (i = 0; i < len; i++) {
        if (arr[i] >= avg) {
            if (!first) printf(" ");
            printf("%d", arr[i]);
            first = 0;
        }
    }
    printf("\n");
}

int main(void) {
    int len;
    int n[20];
    int i;
    scanf("%d", &len);
    for (i = 0; i < len; i++) {
        scanf("%d", &n[i]);
    }
    solve(n, len);
    return 0;
}
