/* https://leetcode.cn/problems/array-partition/ */
#include "LC.h"

int arrayPairSum(vector<int>& nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i += 2) {
        ans += min(nums[i], nums[i + 1]);
    }
    return ans;
}

int main(void) {
    vector<int> nums{6,2,6,5,1,2};
    cout << arrayPairSum(nums);
    return 0;
}