/* https://leetcode.cn/problems/combinations/ */
#include "LC.h"

// 解题核心：将问题抽象成树，再使用 dfs 来按题目要求遍历树中节点
class Solution {
public:
    void backTracking(int n, int k, int startIndex) {
        // 终止条件
        if(path.size() == k) {
            ans.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; ++i) {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return ans;
    }
private:
    vector<int> path;
    vector<vector<int>> ans;
};

int main() {
    Solution solution;
    for(auto i : solution.combine(4, 2)) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}