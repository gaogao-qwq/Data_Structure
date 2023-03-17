#include <bits/stdc++.h>
using namespace std;

// 01背包
int main() {
    ios_base::sync_with_stdio(false);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> items(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> items[i][0] >> items[i][1];
    }
    vector<vector<long long>> dp(m, vector<long long>(n + 1, 0));
    // 初始化 dp 数组第一行
    for (int i = 1; i <= n; ++i) {
        if (items[0][0] <= i) dp[0][i] = items[0][0] * items[0][1];
    }
    // 构建 dp 数组
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = items[i][0] > j ?
            dp[i - 1][j] : max(dp[i - 1][j], dp[i - 1][j - items[i][0]] + items[i][0] * items[i][1]);
        }
    }
    cout << dp[m - 1][n];
    return 0;
}