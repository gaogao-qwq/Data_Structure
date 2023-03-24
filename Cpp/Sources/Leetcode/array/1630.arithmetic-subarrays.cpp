#include "LC.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); ++i) {
            vector<int> tmps;
            for (int k = l[i]; k <= r[i]; ++k) {
                tmps.push_back(nums[k]);
            }
            sort(tmps.begin(), tmps.end());
            if (tmps.size() <= 2) {
                ans.push_back(true);
                continue;
            }
            bool isArithemetic = true;
            int diff = tmps[1] - tmps[0];
            for (int j = 2; j < tmps.size(); ++j) {
                if (tmps[j] - tmps[j - 1] != diff) {
                    isArithemetic = false;
                    break;
                }
            }
            ans.push_back(isArithemetic);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{4,6,5,9,3,7};
    vector<int> l{0,0,2};
    vector<int> r{2,3,5};
    auto ans = s.checkArithmeticSubarrays(nums,l,r);
    for (auto i : ans) {
        cout << i << endl;
    }
}
