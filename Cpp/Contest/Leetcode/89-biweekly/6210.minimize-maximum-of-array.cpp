/* https://leetcode.cn/problems/minimize-maximum-of-array/ */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long ans = -1, s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            ans = max(ans, (s + i) / (i + 1));
        }
        return ans;
    }
};

int main() {
    vector<int> nums{13,13,20,0,8,9,9};
    Solution s;
    cout << s.minimizeArrayValue(nums);
    return 0;
}