#include "LC.h"

/*
 * 爬楼梯：
 * 1、确定 dp 数组含义，dp[i] 为从第0阶爬到第i阶的方法数
 * 2、递推公式 dp[i] = dp[i - 1] + dp[i - 2] 即：爬至第i阶的方法数为爬上前两阶方法数之和。
 * 3、dp数组如何初始化 直接初始化 dp[0] dp[1] dp[2] 为前两阶的方法数（第0阶初始化为0）
 * 4、遍历方向 从前往后
 * 5、打印 dp 数组
 */

int climbStairs(int n) {
    vector<int> dp(n + 3);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << climbStairs(3);
    return 0;
}