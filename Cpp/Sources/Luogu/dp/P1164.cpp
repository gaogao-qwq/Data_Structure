#include <bits/stdc++.h>
using namespace std;

// 01背包改编
int main() {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    vector<int> dp(M + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = M; j >= v[i]; --j) {
            dp[j] += dp[j - v[i]];
        }
        // for (auto i : dp) {
        //     cout << i << " ";
        // }
        // cout << endl;
    }
    cout << dp[M];
    return 0;
}