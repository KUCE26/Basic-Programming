#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int words = 1;
    for (char c : s) {
        if (c == ' ') words++;
    }
    cout << "단어 수: " << words << "\n";
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}
