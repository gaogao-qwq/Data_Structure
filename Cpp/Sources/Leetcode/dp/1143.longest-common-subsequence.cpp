#include "LC.h"

// 二维dp
// dp[i][j] 表示 text1[0 : i - 1] 和 text2[0 : j - 1] 的最长公共子序列
// 当 text1[i - 1] == text2[j - 1] 时 dp[i][j] = dp[i − 1][j − 1] + 1
// 当 text1[i - 1] != text2[j - 1] 时 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    continue;
                }
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main() {
    return 0;
}