#include "LC.h"

// 由于题目要求我们必须实现 O(log n) 的时间复杂度，所以只能用二分搜索
// 虽然力扣这道题的测试用例很水，直接用 c++ 的 sort 也能过就是了。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < nums[r]) {
                r = mid;
                continue;
            }
            l = mid + 1;
        }
        return nums[l];
    }
};

int main() {
    Solution s;
    vector<int> nums{5,1,2,3,4};
    cout << s.findMin(nums) << endl;
    return 0;
}