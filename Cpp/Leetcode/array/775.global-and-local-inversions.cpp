#include "LC.h"

// 只要出现一个全局倒置而非局部倒置，就返回false
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int _max = nums[0];
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] < _max) return false;
            _max = max(_max, nums[i - 1]);
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,3,0,0,2,4};
    cout << boolalpha <<s.isIdealPermutation(nums);
    return 0;
}