/* https://leetcode.cn/problems/fruit-into-baskets/ */
#include "LC.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, ans = 0;
        int ln = fruits[left], rn = fruits[right];
        while (right < fruits.size()) {
            if (fruits[right] == rn || fruits[right] == ln) {
                ans = max(ans, right + 1 - left);
                ++right;
            } else {
                left = right - 1;
                ln = fruits[left];
                while (left >= 1 && fruits[left - 1] == ln) --left;
                rn = fruits[right];
                ans = max(ans, right + 1 - left);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}