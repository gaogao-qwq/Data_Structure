#include <bits/stdc++.h>
using namespace std;

int N = 0, dp[11], ans = 0;
string str;

int main(int argc, char *argv[]) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        int si = str[0] - '0', ei = str[str.length() - 1] - '0';
        dp[ei] = max(dp[ei], dp[si] + 1);
    }
    for (int i : dp) {
        ans = max(ans, i);
    }
    cout << N - ans;
}