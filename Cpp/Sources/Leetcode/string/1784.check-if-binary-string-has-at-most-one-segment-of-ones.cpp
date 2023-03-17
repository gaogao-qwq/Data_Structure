/* https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/ */
#include "LC.h"

    bool checkOnesSegment(string s) {
        if(s.length() == 1) return true;
        int cnt = 0;
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] == '0') {
                ++cnt;
                continue;
            }
            if(cnt > 0 && s[i] == '1') return false;
        }
        return true;
    }

int main() {
    cout << boolalpha << checkOnesSegment("1001");
    return 0;
}