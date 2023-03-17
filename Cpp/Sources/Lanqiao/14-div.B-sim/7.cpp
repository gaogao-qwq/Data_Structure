#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (uset.find(s[i]) != uset.end()) s[i] -= 32;
    }
    cout << s;
    return 0;
}