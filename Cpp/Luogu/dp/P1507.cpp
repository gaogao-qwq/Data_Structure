#include <bits/stdc++.h>
using namespace std;

// 一维存体积 V，一维存重量W
int main() {
    int V = 0, W = 0, N = 0;
    cin >> V >> W >> N;
    vector<int> v(N), w(N), c(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i] >> c[i];
    }
    
    vector<vector<int>> dp(V + 1, vector<int>(W + 1, 0));
    for (int k = 0; k < N; ++k) {
        for (int i = V; i >= v[k]; --i) {
            for (int j = W; j >= w[k]; --j) {
                dp[i][j] = max(dp[i][j], dp[i - v[k]][j - w[k]] + c[k]);
            }
        }
    }
    cout << dp[V][W];
    return 0;
}