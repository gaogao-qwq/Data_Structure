#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N = 0, ans = 0;
array<ll, 100002> arr;
array<ll, 100002> dp;
array<array<ll, 2>, 100002> cnt;

int main(int argc, char *argv[]) {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    for (int i = 1; i <= N; ++i) dp[i] = dp[i - 1] ^ arr[i];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= 20; ++j) {
            ++cnt[j][dp[i] >> j & 1];
        }
    }
    for (int i = 0; i <= 20; ++i) {
        ans += cnt[i][0] * cnt[i][1] * (1 << i);
    }
    cout << ans;
}