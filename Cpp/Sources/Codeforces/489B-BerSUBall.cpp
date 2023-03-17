#/* https://codeforces.com/problemset/problem/489/B */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n = 0, m = 0, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    if(n == 1 && m == 1 && a[0] >= b[0] - 1 && a[0] <= b[0] + 1) {
        cout << 1;
        return 0;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto i = a.begin(), j = b.begin();
    while(i != a.end() && j != b.end()) {
        if(*i >= *j - 1 && *i <= *j + 1) {
            ++i, ++j;
            ++cnt;
            if(i == a.end() || j == b .end()) {
                break;
            }
            continue;
        }
        if(*i < *j) {
            ++i;
        } else {
            ++j;
        }
    }
    cout << cnt;
    return 0;
}