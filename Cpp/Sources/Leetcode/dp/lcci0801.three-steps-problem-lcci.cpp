/* https://leetcode.cn/problems/three-steps-problem-lcci/ */
#include "LC.h"

/*
 * 三步问题：
 * 1、dp[i] 代表到第i阶的走法数
 * 2、初始化 dp[1] dp[2] dp[3] 分别为1 2 4。
 * 3、dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
 * 4、遍历方向从前往后
 */

// int waysToStep(int n) {
//     vector<long long> dp(n + 3);
//     dp[1] = 1, dp[2] = 2, dp[3] = 4;
//     for(int i = 4; i <= n; ++i) {
//         dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007;
//     }
//     return dp[n];
// }

// 优化做法：因为dp[i]只与前三项相关，所以只需要维护一个长度为3的dp数组即可
int waysToStep(int n) {
        int dp[3] = {1, 1, 2}; // 初始化 i = 0, 1, 2
        for(int i = 3; i <= n; ++i) {
            dp[i % 3] = ((long)dp[0] + dp[1] + dp[2]) % 1000000007;
        }
        return dp[n % 3];
}

int main() {
    cout << waysToStep(5);
    return 0;
}