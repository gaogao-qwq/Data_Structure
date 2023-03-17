#include "LC.h"

// 数组翻转，分割后分别翻转，喜提90%
// void rotate(vector<int>& nums, int k) {
//     // 观察规律可得，k > nums.size() 实际上就是轮转 k - nums.size() 次。
//     k %= nums.size();
//     reverse(nums.begin(), nums.end());
//     reverse(nums.begin(), nums.begin() + k);
//     reverse(nums.begin() + k, nums.end());
// }

// 栈 喜提77%
void rotate(vector<int>& nums, int k) {
    // 观察规律可得，k > nums.size() 实际上就是轮转 k - nums.size() 次。
    k %= nums.size();
    if(nums.size() == k || nums.size() == 1) return;
    stack<int> stk;
    for(int i = 0; i < k; ++i) {
        stk.push(nums[nums.size() - 1 - i]);
    }
    for(int i = nums.size() - k - 1, j = nums.size() - 1; i >= 0; --i, --j) {
        nums[j] = nums[i];
    }
    for(int i = 0; i < k; ++i) {
        nums[i] = stk.top();
        stk.pop();
    }
}

// 暴力O(n2)喜提超时
// void rotate(vector<int>& nums, int k) {
//     for(int i = 0; i < k; ++i) {
//         int tmp = nums[nums.size() - 1];
//         for(int j = nums.size() - 1; j > 0; --j) {
//             nums[j] = nums[j - 1];
//         }
//         nums[0] = tmp;
//     }
// }

int main() {
    vector<int> nums{1,2,3,4,5,6,7};
    rotate(nums, 10);
    for(auto i : nums) {
        cout << i << " ";
    }
    return 0;
}