#include <iostream>
using namespace std;

int main() {
    int n;
    int a[10][10];
    int b[10][10];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) b[i][j] = a[n - 1 - j][i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << b[i][j] << (j + 1 < n ? " " : "\n");
    }
    return 0;
}
