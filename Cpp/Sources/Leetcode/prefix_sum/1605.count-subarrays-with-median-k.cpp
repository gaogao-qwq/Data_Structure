#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int kIndex = (int)distance(nums.begin(), find(nums.begin(), nums.end(), k));
        unordered_map<int, int> cnt{{0, 1}};
        for (int i = kIndex - 1, sum = 0; i >=0; --i) {
            sum += nums[i] < k ? 1 : -1;
            ++cnt[sum];
        }
        int ans = cnt[0] + cnt[-1];
        for (int i = kIndex + 1, sum = 0; i < nums.size(); ++i) {
            sum += nums[i] > k ? 1 : -1;
            ans += cnt[sum] + cnt[sum - 1];
        }
        return ans;
    }
};

int main() {
	vector<int> nums{3,2,1,4,5};
	Solution s;
	cout << s.countSubarrays(nums, 4) << endl;
}
