#include <bits/stdc++.h>
using namespace std;

// 01背包
int main() {
    int T = 0, M = 0;
    cin >> T >> M;
    // 初始化数组
    vector<int> time(M), val(M);
    for (int i = 0; i < M; ++i) {
        cin >> time[i] >> val[i];
    }

    vector<vector<int>> dp(M, vector<int>(T + 1));
    // 初始化 dp 数组第一行
    dp[0][0] = 0;
    for (int i = 1; i <= T; ++i) {
        if (time[0] <= i) dp[0][i] = val[0];
    }

    for (int i = 1; i < M; ++i) {
        for (int j = 0; j <= T; ++j) {
            if (time[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + val[i]);
        }
    }

    cout << dp[M - 1][T];
    return 0;
}