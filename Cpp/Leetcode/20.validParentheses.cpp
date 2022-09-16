/* https://leetcode.cn/problems/valid-parentheses/ */
/* https://leetcode.cn/problems/valid-parentheses/solution/zhu-bu-fen-xi-tu-jie-zhan-zhan-shi-zui-biao-zhun-d/ */

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> _hMap {
            {'(', 1}, {'[', 2}, {'{', 3}, {')', 4}, {']', 5}, {'}', 6}
        };
        stack<char> _cStack;
        bool isValid = true;
        for(auto i:s) {
            int val = _hMap[i];
            if (val >= 1 && val <= 3) {
                _cStack.push(i);
            } else if(!_cStack.empty() && _hMap[_cStack.top()] == val - 3) {
                _cStack.pop();
            } else {
                return false;
            }
        }
        if(!_cStack.empty()) {
            return false;
        }
        return isValid;
    }
};

int main(void) {
    Solution solution;
    string s = "()[]{()[()]}";
    cout << solution.isValid(s) << endl;
    return 0;
}