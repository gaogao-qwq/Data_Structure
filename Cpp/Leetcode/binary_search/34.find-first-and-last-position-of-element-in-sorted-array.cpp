#include "LC.h"

// 朴素做法（没有用二分）
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int flag = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target) {
                flag = 0;
                continue;
            }
            ++flag;
            if (flag == 1) {
                ans[0] = ans[1] = i;
                continue;
            }
            if (flag) {
                ans[1] = i;
            }
        }
        return ans;
    }
};

//TODO: 二分
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    }
};

int main() {
    return 0;
} 