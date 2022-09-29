/* https://leetcode.cn/problems/baseball-game/ */
#include "LC.h"

// 简单模拟题，考察栈的运用
class Solution {
public:
    bool isNumber(string s) {
        for(auto i : s) {
            if(i == '-') continue;
            if(!isdigit(i)) return false;
        }
        return true;
    }
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int ans = 0;
        for(auto i : operations) {
            if(isNumber(i)) {
                stk.push(stoi(i));
                continue;
            }
            if(i == "C") {
                stk.pop();
                continue;
            }
            if(i == "D") {
                stk.push(stk.top() * 2);
                continue;
            }
            if(i == "+") {
                int curr = stk.top();
                stk.pop();
                int prev = stk.top();
                stk.push(curr);
                stk.push(curr + prev);
                continue;
            }
        }
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> ops{"5","2","C","D","+"};
    cout << solution.calPoints(ops);
    return 0;
}