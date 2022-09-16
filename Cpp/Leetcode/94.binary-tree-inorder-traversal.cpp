/* https://leetcode.cn/problems/binary-tree-inorder-traversal/ */
#include <iostream>
#include "LCBinaryTree.h"
using namespace std;

void inorder(TreeNode *root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }
    if(root->left != nullptr) {
        inorder(root->left, ans);
    }
    ans.push_back(root->val);
    if(root->right != nullptr) {
        inorder(root->right, ans);
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans{};
    inorder(root, ans);
    return ans;
}

int main(void) {
    vector<TreeNodePtr> input{ 1, nullptr, 2, 3 };
    TreeNode *root = generateTree(input);
    for(auto i : inorderTraversal(root)) {
        cout << i << ' ';
    }
    return 0;
}