#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 3 == 0 && nums[i] % 2 == 0) {
                sum += nums[i];
                ++cnt;
            }
        }
        return (cnt == 0) ? 0 : sum / cnt;
    }
};

int main() {
    vector<int> nums{4,4,9,10};
    Solution s;
    cout << s.averageValue(nums);
    return 0;
}