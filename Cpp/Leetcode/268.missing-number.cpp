/* https://leetcode.cn/problems/missing-number/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = (n + 1) * n / 2; // Sn=n*a1+n(n-1)d/2 利用等差数列求和
        // for(int i = 0; i < nums.size(); ++i) {
        //     sum -= nums[i];
        // }
        // return sum;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            ans ^= nums[i]; // 利用异或运算
            ans ^= i;
        }
        return ans;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums = {3, 0, 1};
    vector<int> &r = nums;
    cout << solution.missingNumber(r) << endl;
    return 0;
}