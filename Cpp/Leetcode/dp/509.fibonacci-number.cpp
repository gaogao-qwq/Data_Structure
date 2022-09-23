/* https://leetcode.cn/problems/fibonacci-number/ */
#include "LC.h"

/*
 * 斐波那契数：
 * 1、确定 dp 数组含义，dp[i] 为第 i 个斐波那契数的值
 * 2、递推公式 dp[i] = dp[i - 1] + dp[i - 2]
 * 3、dp数组如何初始化 直接初始化 dp[0] dp[1] dp[2] 为前三个斐波那契数的值
 * 4、遍历方向 从前往后
 * 5、打印 dp 数组
 */

int fib(int n) {
    vector<int> dp(n + 2);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << fib(4);
    return 0;
}