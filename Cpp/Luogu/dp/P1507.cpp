#include <bits/stdc++.h>
using namespace std;

// 不进行状态压缩为3维dp数组，压缩后为2维
int main() {
    int V = 0, W = 0, N = 0;
    cin >> V >> W >> N;
    vector<int> v(N), w(N), c(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i] >> c[i];
    }
    
    vector<vector<int>> dp(N, vector<int>());
    return 0;
}