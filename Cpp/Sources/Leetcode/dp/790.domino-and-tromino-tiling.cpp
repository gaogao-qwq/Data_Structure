/* https://leetcode.cn/problems/domino-and-tromino-tiling/ */
#include "LC.h"

// https://leetcode.cn/problems/domino-and-tromino-tiling/solution/by-endlesscheng-umpp/
// dp，找规律 + 递推公式简化
class Solution {
    const int MOD = 1e9 + 7;
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        long long dp[n + 1];
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (2 * dp[n - 1] + dp[n - 3]) % MOD;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numTilings(5);
    return 0;
}