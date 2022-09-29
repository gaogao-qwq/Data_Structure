/* https://leetcode.cn/problems/house-robber/ */
#include "LC.h"

/*
 * 1、确定 dp 数组含义 dp[i] 代表前i间房子能够偷取到的最大金额
 * 2、递推公式 dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2])
 * 3、dp数组如何初始化 dp[0] = 0, dp[1] = nums[0] 没有房子自然为0，只有一间房子自然只能偷第一间
 * 4、遍历方向 从前往后
 */
class Solution {
public:
    // 观察可得，我们并不需要一直维护一个长度为nums.size()+1的数组
    // 我们在每次计算 dp[i] 时实际上只需要知道 dp[i - 1] 和 dp[i - 2] 的值
    // 因此可以使用两个 curr 和 prev 变量 代替 dp 数组，实现O(1)空间复杂度
    int badRob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }
        return dp[nums.size()];
    }
    // 空间优化
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int curr(0), prev(0);
        for(auto i : nums) {
            int temp = max(curr, i + prev);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,7,9,3,1};
    cout << solution.rob(nums);
    return 0;
}