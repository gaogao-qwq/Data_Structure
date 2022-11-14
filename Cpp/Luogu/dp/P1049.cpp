#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 0, n = 0;
    cin >> V >> n;
    vector<int> item(n);
    for (int i = 0; i < n; ++i) {
        cin >> item[i];
    }

    // 初始化 dp 数组第一行
    vector<vector<int>> dp(n, vector<int>(V + 1));
    for (int i = 0; i <= V; ++i) {
        dp[0][i] = item[0] < i ? item[0] : 0;
    }
    // 状态转移方程 dp[i][j] = item[i] < j ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - item[i]])
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= V; ++j) {
            dp[i][j] = item[i] > j ? dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - item[i]] + item[i]);
        }
    }
    cout << V - dp[n - 1][V];
    return 0;
}