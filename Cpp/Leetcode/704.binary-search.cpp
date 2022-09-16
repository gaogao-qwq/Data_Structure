/* https://leetcode.cn/problems/binary-search/ */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> nums{-1,0,3,5,9,12};
    int target = 9, n = nums.size(), mid = n / 2;
    if(nums[mid] <= target) {
        for(int i = mid; i < n; ++i) {
            if(nums[i] == target) {
                return i;
            }
        }
    } else {
        for(int i = mid; i >= 0; --i) {
            if(nums[i] == target) {
                cout << i;
                return i;
            }
        }
    }
    return -1;
}