/* https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/ */
#include "LC.h"

int maxProduct(vector<int>& nums) {
    if(nums.size() == 2) return (nums[1] - 1) * (nums[0] - 1);
    sort(nums.begin(), nums.end());
    return (*nums.rbegin() - 1) * (*(nums.rbegin() + 1) - 1);
}

int main() {
    vector<int> nums{3,4,5,2};
    cout << maxProduct(nums);
    return 0;
}