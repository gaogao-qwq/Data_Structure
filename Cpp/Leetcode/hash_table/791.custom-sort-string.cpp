/* https://leetcode.cn/problems/custom-sort-string/ */
#include "LC.h"

// 调库
class Solution {
public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return order.find(a) < order.find(b);
        });
        return s;
    }
};

int main() {
    Solution s;
    cout << s.customSortString("cba", "abcd");
    return 0;
}