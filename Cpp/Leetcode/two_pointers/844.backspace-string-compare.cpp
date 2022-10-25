#include "LC.h"

// 栈做法（注意这里直接用字符串是为了方便判断，因为栈能做的事情字符串也能做）
class Solution1 {
public:
    bool backspaceCompare(string s, string t) {
        string stk1, stk2;
        // 加上判断实现一次遍历，缺点就是空间复杂度是 O(n + m) 和判断语句的额外常数时间复杂度开销
        int n = s.length() > t.length() ? s.length() : t.length();
        for (int i = 0; i < n; ++i) {
            if (i < s.length()) {
                if (s[i] != '#') stk1.push_back(s[i]);
                else if (!stk1.empty()) stk1.pop_back();
            }
            if (i < t.length()) {
                if (t[i] != '#') stk2.push_back(t[i]);
                else if (!stk2.empty()) stk2.pop_back();
            }
        }
        if (stk1 != stk2) return false;
        return true;
    }
};

// 双指针做法
class Solution2 {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    cout << boolalpha << s1.backspaceCompare("xywrrmp", "xywrrmu#p");
    cout << boolalpha << s2.backspaceCompare("bxj##tw", "bxj###tw");
    return 0;
}