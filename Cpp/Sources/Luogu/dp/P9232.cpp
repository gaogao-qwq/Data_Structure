#include <bits/stdc++.h>
using namespace std;

string num;
int N = 0, ans = 0;
array<array<int, 5002>, 5002> dp;

int main(int argc, char *argv[], char *envp[]) {
    cin >> num;
    N = num.length();
    for (int i = 0; i < N; ++i) {
        dp[i][i] = 0;
        if (i < N - 1) dp[i][i + 1] = (num[i] > num[i + 1]);
    }
    for (int len = 3; len <= N; ++len) {
        for (int i = 0; i < N - len + 1; ++i) {
            int j = i + len - 1;
            if (num[i] == num[j]) dp[i][j] = dp[i + 1][j - 1];
            if (num[i] > num[j]) dp[i][j] = 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            ans += dp[i][j];
        }
    }
    cout << ans;
}