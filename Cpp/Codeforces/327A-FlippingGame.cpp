/* https://codeforces.com/problemset/problem/327/A */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, cnt = 0;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> dp(a);
    for(int i = 0; i < n; i++) {
        int c = 0;
        cin >> c;
        if(c == 1) {
            a[i] = -1, cnt++;
        }
        else a[i] = 1;
    }
    dp[0] = a[0];
    int maxc = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]), maxc = max(maxc, dp[i]);
    }
    cout << maxc + cnt;
    return 0;
}