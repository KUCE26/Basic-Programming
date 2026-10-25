#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i] << (i + 1 < n ? " " : "\n");
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) cout << v[i] << (i + 1 < n ? " " : "\n");
    return 0;
}
