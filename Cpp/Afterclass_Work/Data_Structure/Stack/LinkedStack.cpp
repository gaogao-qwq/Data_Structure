#include "LinkedStack.hpp"
#include <bits/stdc++.h>
using namespace std;

// 链栈
bool isValid(string s) {
    unordered_map<char, int> _hMap {
            {'(', 1}, {'[', 2}, {'{', 3}, {')', 4}, {']', 5}, {'}', 6}
    };
    LinkedStack<char> stk;
    bool isValid = true;
    for(auto i : s) {
        int val = _hMap[i];
        if (val >= 1 && val <= 3) {
            stk.push(i);
        } else if(!stk.empty() && _hMap[stk.top()] == val - 3) {
            stk.pop();
        } else {
            return false;
        }
    }
    if(!stk.empty()) {
        return false;
    }
    return isValid;
}

int main() {
    string s1 = "()[]{}", s2 = "{)";
    cout << boolalpha << isValid(s1) << endl << isValid(s2);
    return 0;
}