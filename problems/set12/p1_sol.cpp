#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (i == 0 || x > mx) mx = x;
        if (i == 0 || x < mn) mn = x;
    }
    cout << "합계: " << sum << " 최댓값: " << mx << " 최솟값: " << mn << "\n";
    return 0;
}
