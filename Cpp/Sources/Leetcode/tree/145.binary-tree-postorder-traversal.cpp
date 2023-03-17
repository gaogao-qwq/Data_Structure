/* https://leetcode.cn/problems/binary-tree-postorder-traversal/ */
#include "LCBinaryTree.h"

void postorder(TreeNode *root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }
    if(root->left != nullptr) {
        postorder(root->left, ans);
    }
    if(root->right != nullptr) {
        postorder(root->right, ans);
    }
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans{};
    postorder(root, ans);
    return ans;
}

int main(void) {
    vector<TreeNodePtr> input{ 1, nullptr, 2, 3 };
    TreeNode *root = generateTree(input);
    for(auto i : postorderTraversal(root)) {
        cout << i << ' ';
    }
    return 0;
}