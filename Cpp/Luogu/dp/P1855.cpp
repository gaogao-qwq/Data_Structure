#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, M = 0, T = 0;
    cin >> n >> M >> T;
    vector<int> m(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i] >> t[i];
    }

    vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));
    for (int k = 0; k < n; ++k) {
        for (int i = M; i >= m[k]; --i) {
            for (int j = T; j >= t[k]; --j) {
                dp[i][j] = max(dp[i][j], dp[i - m[k]][j - t[k]] + 1);
            }
        }
    }
    cout << dp[M][T] << endl;
    return 0;
}