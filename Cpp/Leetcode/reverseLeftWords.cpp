/* https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/ */

#include <iostream>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int k) {
        int len = s.size();
        string ans = s;
        for(int i = 0; i < len; ++i) {
            ans[i] = s[(i + k) % len]; // 取模运算的合理运用
        }
        return ans;
    }
};

int main(void) {
    Solution solution;
    string str = "abcdefg";
    cout << solution.reverseLeftWords(str, 2) << endl;
    return 0;
}