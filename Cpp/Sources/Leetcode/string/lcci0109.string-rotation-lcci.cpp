/* https://leetcode.cn/problems/string-rotation-lcci/ */
#include "LC.h"

class Solution {
public:
    // 笨办法，暴力枚举子串
    bool isFlipedStringBad(string s1, string s2) {
        if(s1.size() == 0 && s2.size() == 0) return true;
        if(s1.size() != s2.size()) {
            return false;
        }
        for(int i = 0; i < s1.size(); ++i) {
            string tmp = s1.substr(i + 1, s1.size() - i) + s1.substr(0, i + 1);
            if(tmp == s2) {
                return true;
            }
        }
        return false;
    }
    // 将两个s2连接起来：erbottle waterbottle wat 不难发现其中出现了原本的s1
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s2 + s2).find(s1) != string::npos;
    }
};

int main() {
    Solution solution;
    string s1 = "waterbottle", s2 = "erbottlewat";
    cout << boolalpha << solution.isFlipedString(s1, s2);
    return 0;
}