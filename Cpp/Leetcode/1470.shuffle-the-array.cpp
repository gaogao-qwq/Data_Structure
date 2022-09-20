/* https://leetcode.cn/problems/shuffle-the-array/ */
#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    if(n == 1) return nums;
    vector<int> ans{};
    for(int i = 0, j = n; i < n; ++i, ++j) {
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
    }
    return ans;
}

int main() {
    vector<int> nums{2,5,1,3,4,7};
    vector<int> ans = shuffle(nums, 3);
    return 0;
}