#include "LC.h"

// 铁超时，简单问题复杂化，你就非得惦记着你那b双指针？
class Solution1 {
public:
    int partitionDisjoint(vector<int>& nums) {
        int r = nums.size() - 1, l = 0;
        int maxl = nums[0], minr = nums[r];
        while (l < r) {
            maxl = *max_element(nums.begin(), nums.begin() + l), minr = *min_element(nums.end() - (nums.size() - r), nums.end() - 1);
            if (maxl <= minr) {
                --r;
                continue;
            }
            if (maxl > minr) {
                minr = nums[++r];
                ++l;
                continue;
            }
            ++l;
        }
        return l + 1;
    }
};

// 维护左子数组最大值 和 遍历到当前位置的最大值
class Solution2 {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans = 0;
        int lmax = nums[0], _max = lmax;
        for (int i = 1; i < nums.size(); ++i) {
            if (lmax > nums[i]) {
                ans = i;
                lmax = _max;
                continue;
            }
            _max = max(nums[i], _max);
        }
        return ans + 1;
    }
};


int main() {
    vector<int> nums1{1,1}, nums2{3,1,8,4,9,7,12,0,0,12,6,12,6,19,24,90,87,54,92,60,31,59,75,90,20,38,52,51,74,70,86,20,27,91,55,47,54,86,15,16,74,32,68,27,19,54,13,22,34,74,76,50,74,97,87,42,58,95,17,93,39,33,22,87,96,90,71,22,48,46,37,18,17,65,54,82,54,29,27,68,53,89,23,12,90,98,42,87,91,23,72,35,14,58,62,79,30,67,44,48};
    Solution1 s1;
    cout << s1.partitionDisjoint(nums2) << endl;
    return 0;
}
