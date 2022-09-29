/* https://leetcode.cn/problems/letter-case-permutation/ */
#include "LC.h"

// 解题核心：将问题抽象成树，再使用 dfs 来按题目要求遍历树中节点
// 这道题其实并没有回溯的思想，只需要递归到底部后直接将结果推入ans即可。
class Solution {
public:
    void dfs(string s, int index) {
        if(index == s.length()) {
            ans.push_back(s);
            return;
        }
        dfs(s, index + 1);
        if(s[index] >= 'a' && s[index] <= 'z' || s[index] >= 'A' && s[index] <= 'Z') {
            // 任何字母异或空格即可转换大小写
            s[index] ^= ' ';
            dfs(s, index + 1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        int len = s.size();
        dfs(s, 0);
        return ans;
    }

private:
    vector<string> ans;
    int index = 0;
};

int main() {
    string s = "a1b2";
    Solution solution;
    vector<string> ans = solution.letterCasePermutation(s);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}