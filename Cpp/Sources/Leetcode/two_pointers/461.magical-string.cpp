#include "LC.h"

// 使用双指针在 O(n) 时间复杂度内构建目标数组顺带记个数完事儿
class Solution {
public:
    int magicalString(int n) {
        vector<int> magic(n + 1, 0);
        magic[0] = 1;
        int l = 1, r = 1, value = 1, cnt = 2, ans = 1;
        while (r < n) {
            // note: 1 ^ 3 = 2, 2 ^ 3 = 1
            value ^= 3;
            while (cnt-- > 0 && r < n) {
                magic[r++] = value;
                if (value == 1) ++ans;
            }
            cnt = magic[l++];
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.magicalString(6) << endl;
    return 0;
}