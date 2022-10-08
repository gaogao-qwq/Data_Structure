/* https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/ */
#include "LC.h"

    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(auto i : s) {
            if(stk.empty()) {
                stk.push(i);
                continue;
            }
            if(stk.top() == '(' && i == ')') {
                stk.pop();
                continue;
            }
            stk.push(i);
        }
        return stk.size();
    }

int main() {
    cout << minAddToMakeValid("()(");
    return 0;
}