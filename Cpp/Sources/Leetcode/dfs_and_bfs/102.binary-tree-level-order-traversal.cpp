/* https://leetcode.cn/problems/binary-tree-level-order-traversal/ */
#include "LCBinaryTree.h"

vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<TreeNode *> que;
    que.push(root);
    while(!que.empty()) {
        int n = que.size();
        vector<int> level;
        for(int i = 0; i < n; ++i) {
            auto curr = que.front();
            que.pop();
            level.push_back(curr->val);
            if(curr->left != nullptr) {
                que.push(curr->left);
            }
            if(curr->right != nullptr) {
                que.push(curr->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    vector<TreeNodePtr> input{3,9,20,nullptr,nullptr,15,7};
    auto root = generateTree(input);
    auto ans = levelOrder(root);
    return 0;
}
