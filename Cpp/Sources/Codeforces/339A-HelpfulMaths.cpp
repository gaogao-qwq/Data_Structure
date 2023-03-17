/* https://codeforces.com/problemset/problem/339/A */
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    string s = "";
    cin >> s;
    if(s.size() == 1) {
        cout << s;
        return 0;
    }
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '+') {
            s.erase(i, 1);
        }
    }
    sort(s.begin(), s.end());
    for(int i = 1; i < s.size(); i += 2) {
        s.insert(i, 1, '+');
    }
    cout << s;
    return 0;
}