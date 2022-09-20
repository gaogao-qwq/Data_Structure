/* https://leetcode.cn/problems/split-a-string-in-balanced-strings/ */
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int balancedStringSplit(string s) {
    int ans = 0;
    stack<char> stk;
    for(auto i = s.begin(); i != s.end(); ++i) {
        if(stk.empty()) {
            ++ans;
            stk.push(*i);
            continue;
        }
        if(stk.top() != *i) {
            stk.pop();
        } else {
            stk.push(*i);
        }
    }
    return ans;
}

int main() {
    cout << balancedStringSplit("RLRRLLRLRL");
    return 0;
}