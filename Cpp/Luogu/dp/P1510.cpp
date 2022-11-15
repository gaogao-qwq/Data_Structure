#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 0, n = 0, C = 0;
    cin >> V >> n >> C;
    vector<int> v(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> c[i];
    }

    vector<int> dp(V + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + c[i]);
        }
    }
    if (C - dp[V] < 0) cout << "Impossible";
    else cout << C - dp[V];
    return 0;
}