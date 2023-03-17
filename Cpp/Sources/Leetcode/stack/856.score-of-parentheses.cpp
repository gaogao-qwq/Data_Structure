/* https://leetcode.cn/problems/score-of-parentheses/ */
#include "LC.h"

    int scoreOfParentheses(string s) {
        stack<char> stk;
        for(auto i : s) {
            if(i == '(') {
                stk.push(i);
                continue;
            }
            char tmp = stk.top();
            if(tmp == '(') {
                stk.push('1');
                continue;
            }
            int sum = tmp - '0';
            tmp = stk.top();
            while(stk.top() != '(') {
                stk.pop();
                sum += tmp - '0';
            }
            stk.push((char)((sum << 1) + '0'));
        }
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top() - '0';
            stk.pop();
        }
    }

int main() {
    return 0;
}