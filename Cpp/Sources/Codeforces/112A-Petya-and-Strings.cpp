/* https://codeforces.com/problemset/problem/112/A */
#include <iostream>
using namespace std;

int main(void) {
    string s1 = "", s2 = "";
    cin >> s1;
    cin >> s2;
    for(int i = 0; i < s1.size(); ++i) {
        if(toupper(s1[i]) == toupper(s2[i])) {
            continue;
        }
        if(toupper(s1[i]) > toupper(s2[i])) {
            cout << 1;
            return 0;
        } else {
            cout << -1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}