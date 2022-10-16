#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> uset;
        for (auto i : nums) {
            if (i < 0 && uset.find(i) == uset.end()) {
                uset.emplace(i);
            }
        }
        int ans = -1;
        for (auto i : nums) {
            if (uset.find((-i)) != uset.end()) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{-1,10,6,7,-7,1};
    Solution s;
    cout << s.findMaxK(nums);
    return 0;
}