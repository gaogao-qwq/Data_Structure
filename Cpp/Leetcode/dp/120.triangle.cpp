/* https://leetcode.cn/problems/triangle/ */
#include "LC.h"

/*
 * dp[i][j] 表示从点 (i, j) 到底边的最小路径和。
 * dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]
 * 遍历方向：自底向上
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
    // TODO：空间优化
};

int main() {
    Solution solution;
    vector<vector<int>> triangle{{2},
                                 {3,4},
                                 {6,5,7},
                                 {4,1,8,3}};
    cout << solution.minimumTotal(triangle);
    return 0;
}