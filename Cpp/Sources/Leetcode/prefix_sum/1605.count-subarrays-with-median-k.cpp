#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int ans = 0, equalIndex = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == k) { nums[i] = 0; equalIndex = i; continue; }
            if (nums[i] > k) { nums[i] = 1; continue; }
            if (nums[i] < k) { nums[i] = -1; continue; }
        }
        for (int l = 0; l < nums.size(); ++l) {
            int prefixSum = 0;
            bool containEqual = false;
            for (int r = l; r < nums.size(); ++r) {
                prefixSum += nums[r];
                if (r == equalIndex) containEqual = true;
                if (containEqual && (r - l + 1) % 2 == 0 && prefixSum == 1) {++ans;continue;}
                if (containEqual && prefixSum == 0) {++ans;continue;}
            }
        }
        return ans;
    }
};

int main() {
	vector<int> nums{3,2,1,4,5};
	Solution s;
	cout << s.countSubarrays(nums, 4) << endl;
}
