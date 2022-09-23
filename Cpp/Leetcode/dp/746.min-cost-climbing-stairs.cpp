/* https://leetcode.cn/problems/min-cost-climbing-stairs/ */
#include "LC.h"

/*
 * 使用最小花费爬楼梯：
 * 1、确定 dp 数组含义，dp[i] 为爬到第i阶要花费的体力
 * 2、递推公式 dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i] 即：前两阶中需要花费体力最少的加上第i阶需花费的体力
 * 3、dp数组如何初始化 直接初始化 dp[0] dp[1] 分别为前两阶各自需要花费的最少体力
 * 4、遍历方向 从前往后
 * 5、打印 dp 数组
 */

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = cost[0], dp[1] = cost[1];
    for(int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(cost);
    return 0;
}