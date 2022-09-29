/* https://leetcode.cn/problems/move-zeroes/ */
/* https://leetcode.cn/problems/move-zeroes/solution/dong-hua-yan-shi-283yi-dong-ling-by-wang_ni_ma/ */
#include "LC.h"

void moveZeroes(vector<int>& nums) {
    if(nums.size() == 1) return;
    int j = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for(int i = j; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> nums{0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}