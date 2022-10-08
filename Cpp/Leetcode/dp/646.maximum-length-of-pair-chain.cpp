/* https://leetcode.cn/problems/maximum-length-of-pair-chain/ */
// 动态规划 贪心 二分查找
#include "LC.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> pairs = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    cout << solution.findLongestChain(pairs) << endl;
    return 0;
}