#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        v.push_back({-score, name});
    }
    sort(v.begin(), v.end());
    for (const auto& p : v) cout << p.second << " " << -p.first << "\n";
    return 0;
}
