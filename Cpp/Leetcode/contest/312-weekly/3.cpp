#include <bits/stdc++.h>
using namespace std;

// TLE answer
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = k; i < n - k; ++i) {
            int left = i - k, right = i + k;
            int lr = i - 1, rr = i + k;
            while(left + 1 <= i) {
                if(left + 1 == i) {
                    ans.push_back(i);
                }
                if(nums[lr] > nums[left] || nums[rr] < nums[right]) break;
                if(nums[left] < nums[left + 1] || nums[right] < nums[right -1]) {
                    break;
                }
                ++left, --right;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

int main() {
    vector<int> nums{693570,409751,33944,16682,26296,545257,827687,885741,970671};
    vector<int> ans = goodIndices(nums, 3);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}