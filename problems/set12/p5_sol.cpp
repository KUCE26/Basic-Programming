#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        cnt[w]++;
    }
    for (const auto& kv : cnt) cout << kv.first << " " << kv.second << "\n";
    return 0;
}
