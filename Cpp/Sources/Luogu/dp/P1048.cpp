#include <bits/stdc++.h>
using namespace std;

// 01背包 滚动数组
int main() {
    int T = 0, M = 0;
    cin >> T >> M;
    vector<int> time(M), val(M);
    for (int i = 0; i < M; ++i) {
        cin >> time[i] >> val[i];
    }

    // dp滚动数组全部置0
    vector<int> dp(T + 1, 0);

    // 先遍历物品
    for (int i = 0; i < M; ++i) {
        // 再遍历背包，记得倒序
        for (int j = T; j >= time[i]; --j) {
            dp[j] = max(dp[j], dp[j - time[i]] + val[i]);
        }
    }

    cout << dp[T];
    return 0;
}