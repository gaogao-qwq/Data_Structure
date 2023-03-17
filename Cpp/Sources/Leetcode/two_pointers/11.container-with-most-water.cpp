/* https://leetcode.cn/problems/container-with-most-water/ */
#include "LC.h"

// 双指针（暴力O(n^2)会超时，别想了）
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size() - 1;
        while(left < right) {
            if(height[left] < height[right]) {
                ans = max((right - left) * height[left], ans);
                ++left;
                continue;
            }
            if(height[left] > height[right]) {
                ans = max((right - left) * height[right], ans);
                --right;
                continue;
            }
            ans = max((right - left) * height[left] ,ans);
            ++left, --right;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height);
    return 0;
}