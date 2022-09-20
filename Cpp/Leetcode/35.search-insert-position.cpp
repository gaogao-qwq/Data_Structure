/* https://leetcode.cn/problems/search-insert-position/ */
#include "LC.h"

int searchInsert(vector<int>& nums, int target) {
    int mid = nums.size() / 2;
    if(target >= nums[mid]) {
        int i = mid;
        for(; i < nums.size(); ++i) {
            if(nums[i] == target) return i; 
            if(target < nums[i]) return i;
        }
        return i;
    } else {
        int i = 0;
        for(; i < mid; ++i) {
            if(nums[i] == target) return i;
            if(target < nums[i]) return i;
        }
        return i;
    }
}

int main() {
    vector<int> nums{1,5,3,6};
    cout << searchInsert(nums,5);
    return 0;
}