#include "LC.h"

    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<bool> mark(s.length(), false);
        int ans = 0, cnt = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                stk.push(i);
                continue;
            }
            if(stk.empty()) {
                mark[i] = true;
                continue;
            }
            stk.pop();
        }
        while(!stk.empty()) {
            mark[stk.top()] = true;
            stk.pop();
        }
        for(auto i : mark) {
            if(i) {
                cnt = 0;
                continue;
            }
            ++cnt;
            ans = max(cnt, ans);
        }
        return ans;
    }

int main() {
    cout << longestValidParentheses(")(())(()");
    return 0;
}