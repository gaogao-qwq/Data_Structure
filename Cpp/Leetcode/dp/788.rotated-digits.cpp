#include <bits/stdc++.h>
using namespace std;

// 数位dp解法 中等
int diffs[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
int rotatedDigitsDP(int n) {
    auto s = to_string(n);
    int m = s.length(), dp[m][2];
    memset(dp, -1, sizeof(dp));

    function<int(int, bool, bool)> f = [&](int i, bool has_diff, bool is_limit) -> int {
        if (i == m) return has_diff; // 只有包含 2/5/6/9 才算一个好数
        if (!is_limit && dp[i][has_diff] >= 0) return dp[i][has_diff];

        int res = 0;
        int up = is_limit ? s[i] - '0' : 9;
        for (int d = 0; d <= up; ++d) // 枚举要填入的数字 d
            if (diffs[d] != -1) // d 不是 3/4/7
                res += f(i + 1, has_diff || diffs[d], is_limit && d == up);
        if (!is_limit) dp[i][has_diff] = res;
        return res;
    };
    return f(0, false, true);
}

// 暴力枚举模拟 简单
int rotatedDigits(int n) {
    auto isValid = [](int val) -> bool {
        if (val == 0) return false; 
        int rot = 0; 
        while (val > 0) {
            int d = val % 10; 
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) rot++; 
            val = val / 10; 
        }
        return rot > 0;
    };
    int ans = 0; 
    for (int i = 1; i <= n; i++){
        if (isValid(i)) ans++; 
    }
    return ans; 
}

int main() {
    int n = 10;
    cout << rotatedDigits(n);
    return 0;
}