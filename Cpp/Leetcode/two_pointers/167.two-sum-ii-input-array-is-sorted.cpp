/* https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/ */
#include "LC.h"

// 双指针，缩减搜索范围。O(n)
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while(i < j) {
        int sum = numbers[i] + numbers[j];
        if(sum < target) {
            ++i;
            continue;
        }
        if(sum > target) {
            --j;
            continue;
        }
        if(sum == target) {
            return {i + 1, j + 1};
        }
    }
    return {};
}

// 喜提超时
vector<int> twoSumBad(vector<int>& numbers, int target) {
    for(auto i = 0; i < numbers.size() - 1; ++i) {
        for(auto j = i + 1; j < numbers.size(); ++j) {
            if(numbers[i] + numbers[j] == target) return {i + 1, j + 1};
        }
    }
    return {};
}

int main() {
    vector<int> numbers{2,7,11,15};
    for(auto i : twoSum(numbers, 9)) {
        cout << i << " ";
    }
    return 0;
}