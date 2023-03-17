#include "LC.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums{2,7,11,15};
    for (auto i : s.twoSum(nums, 9)) {
        cout << i << " ";
    }
    return 0;
}