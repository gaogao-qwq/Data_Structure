/* https://leetcode.cn/problems/second-largest-digit-in-a-string/ */
#include "LC.h"

// 简单哈希表
class Solution {
public:
    int secondHighest(string s) {
        int hash[10] = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                ++hash[s[i] - '0'];
            }
        }
        int cnt = 0;
        for (int i = 9; i >= 0; --i) {
            if (hash[i] != 0) ++cnt;
            if (cnt == 2) return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}