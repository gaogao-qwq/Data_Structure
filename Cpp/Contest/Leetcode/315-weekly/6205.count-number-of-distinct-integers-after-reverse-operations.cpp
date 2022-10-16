#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            nums.push_back(stoi(s));
        }
        unordered_set<int> uset;
        for (auto i : nums) {
            if (uset.find(i) == uset.end()) {
                uset.emplace(i);
            }
        }
        return uset.size();
    }
};

int main() {
    vector<int> nums{1,13,10,12,31};
    Solution s;
    cout << s.countDistinctIntegers(nums);
    return 0;
}