/* https://leetcode.cn/problems/maximum-subarray/ */
#include "LC.h"

/*
 * dp[i] 代表前i个数中最大子数组的和
 * 递推公式 dp[i] = max(dp[i - 1] + nums[i], nums[i])
 * 初始化 dp[0] = nums[0]
 * 遍历方向 从前往后
 */
class Solution {
public:
    int badMaxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    // 空间优化
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0], ans = prev;
        for(int i = 1; i < nums.size(); ++i) {
            int curr = max(prev + nums[i], nums[i]);
            prev = curr;
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main() {
    return 0;
}