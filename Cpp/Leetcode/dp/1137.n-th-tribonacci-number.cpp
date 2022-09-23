/* https://leetcode.cn/problems/n-th-tribonacci-number/ */
#include "LC.h"

/*
 * 泰波那契数：
 * 1、确定 dp 数组含义，dp[i] 为第 i 个泰波那契数的值
 * 2、递推公式 dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
 * 3、dp数组如何初始化 直接初始化 dp[0] dp[1] dp[2] 为前三个泰波那契数的值
 * 4、遍历方向 从前往后
 * 5、打印 dp 数组
 */

int tribonacci(int n) {
    vector<int> dp(n + 3);
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main() {
    cout << tribonacci(4);
    return 0;
}