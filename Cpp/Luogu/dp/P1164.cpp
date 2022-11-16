#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    vector<int> dp(M + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = M; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
        for (auto i : dp) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}