#include "LC.h"

// 朴素做法，没用二分，O(n)
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (target == nums[i]) return i;
        }
        return -1;
    }
};

// 二分
class Solution2 {
public:
    int search(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            // 右移1位等价于除以2
            int mid = (l + r) >> 1; // (l + r) / 2
            if (target == nums[mid]) return mid;
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

// 二分 异或简化逻辑
class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << s2.search(nums, 0);
    return 0;
}