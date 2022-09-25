/* https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/ */
#include "LC.h"

/*
 * dp[i] 代表前i天的最大收益
 * 递推公式：
 * dp[i] = max(dp[i - 1], prices[i] - _min);
 * _min = min(_min, prices[i]);
 * 即：前i天的最大收益 = max(前 i - 1天的最大收益，第i天的价格 - 前 i - 1天中的最小价格)
 * dp 初始化 dp[0] = 0 _min = 
 * 遍历顺序：从前往后
 */
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        int _min = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            dp[i] = max(dp[i - 1], prices[i] - _min);
            _min = min(_min, prices[i]);
        }
        return dp[prices.size() - 1];
    }

int main() {
    vector<int> prices{7,1,5,3,6,4};
    cout << maxProfit(prices);
    return 0;
}