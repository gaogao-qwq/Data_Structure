/* https://codeforces.com/problemset/problem/492/B */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n = 0, l = 0, ans = 0;
    cin >> n >> l;
    vector<int> loc(n);
    for(int i = 0; i < n; ++i) {
        cin >> loc[i];
    }
    sort(loc.begin(), loc.end());
    ans = max(loc[0], l - loc[n - 1]) * 2;
    for(int i = 1; i < loc.size(); ++i) {
        ans = max(ans, loc[i] - loc[i - 1]);
    }
    cout.precision(20);
    cout << fixed << ans / 2.0;
    return 0;
}