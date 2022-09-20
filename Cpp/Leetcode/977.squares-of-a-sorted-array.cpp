/* https://leetcode.cn/problems/squares-of-a-sorted-array/ */
#include "LC.h"

// 暴力排序 O(nlogn)
vector<int> sortedSquares(vector<int>& nums) {
    for(auto &i : nums) {
        i *= i;
    }
    sort(nums.begin(), nums.end());
    return nums;
}

// TODO: 双指针

int main() {
    vector<int> nums{-4,-4,0,3,10};
    for(auto i : sortedSquares(nums)) {
        cout << i << " ";
    }
    return 0;
}