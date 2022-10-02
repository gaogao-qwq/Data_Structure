#include <bits/stdc++.h>
using namespace std;

    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, tmp = 0;
        int m = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            if(nums[i] == m) {
                ++tmp;
            } else {
                tmp = 0;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }

int main() {
    vector<int> nums{1,2,3,4};
    cout << longestSubarray(nums);
    cout << (123456 & 10);
    return 0;
}