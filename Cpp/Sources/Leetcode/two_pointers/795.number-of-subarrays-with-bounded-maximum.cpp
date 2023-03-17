/* https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/ */
#include "LC.h"

// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/solution/tu-jie-yi-ci-bian-li-jian-ji-xie-fa-pyth-n75l/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        int n = nums.size(), ans = 0, i0 = -1, i1 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) i0 = i;
            if (nums[i] >= left) i1 = i;
            ans += i1 - i0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{73,55,36,5,55,14,9,7,72,52};
    cout << s.numSubarrayBoundedMax(nums, 32, 69);
    return 0;
}