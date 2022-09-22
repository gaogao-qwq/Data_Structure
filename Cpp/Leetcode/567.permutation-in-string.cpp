/* https://leetcode.cn/problems/permutation-in-string/ */
// 滑动窗口 哈希表
#include "LC.h"

    bool checkInclusion(string s1, string s2) {
        int n(s1.size()), m(s2.size());
        if(n > m) return false;

        // 因为只会出现小写字母，直接用两个大小为26的 vector 容器存储每个字母出现的次数。
        vector<int> cnt1(26), cnt2(26);

        // 先遍历完s1，如果出现相同直接剪枝。
        for(int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if(cnt1 == cnt2) return true;

        // 遍历s2剩余部分，一边存储每个字母出现的次数一边进行判断。
        for(int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if(cnt1 == cnt2) return true;
        }
        return false;
    }

int main() {
    cout << boolalpha << checkInclusion("ab", "eidbaooo");
    return 0;
}