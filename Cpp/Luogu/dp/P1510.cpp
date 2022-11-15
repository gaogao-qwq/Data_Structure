#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 0, n = 0, C = 0;
    cin >> V >> n >> C;
    vector<int> v(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> c[i];
    }

    vector<int> dp(C + 1, 0);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = C; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
            if (dp[j] >= V) ans = max(ans, C - j);
        }
    }
    if (ans == -1) cout << "Impossible";
    else cout << ans;
    return 0;
}