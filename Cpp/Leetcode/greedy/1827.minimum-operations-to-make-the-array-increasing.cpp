/* https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/ */
#include "LC.h"

// 简单贪心
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int tmp = nums[i];
                nums[i] = nums[i - 1] + 1;
                ans += nums[i] - tmp;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 5, 2, 4, 1};
    cout << s.minOperations(nums) << endl;
    return 0;
}