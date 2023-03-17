/* https://leetcode.cn/problems/generate-parentheses/ */
#include "LC.h"

// dfs回溯解法
class Solution {
private:
    vector<string> ans;
    string s = "";
public:
    void dfs(int lcnt, int rcnt, int n) {
        if(rcnt == n) {
            ans.push_back(s);
            s.pop_back();
            return;
        }
        if(lcnt < n) {
            s.push_back('(');
            dfs(lcnt + 1, rcnt, n);
        }
        if(rcnt < n && rcnt < lcnt) {
            s.push_back(')');
            dfs(lcnt, rcnt + 1, n);
        }
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return ans;
    }
};

int main() {
    Solution s;
    for(auto i : s.generateParenthesis(3)) {
        cout << i << " ";
    }
    return 0;
}