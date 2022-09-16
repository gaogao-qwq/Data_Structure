/* https://leetcode.cn/problems/binary-tree-preorder-traversal/ */
#include <iostream>
#include "LCBinaryTree.h"
using namespace std;

void preorder(TreeNode *root, vector<int> &ans) {
    if(root == nullptr) {
        return;
    }
    ans.push_back(root->val);
    if(root->left != nullptr) {
        preorder(root->left, ans);
    }
    if(root->right != nullptr) {
        preorder(root->right, ans);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans{};
    preorder(root, ans);
    return ans;
}

int main(void) {
    vector<TreeNodePtr> input{ 1, nullptr, 2, 3 };
    TreeNode *root = generateTree(input);
    for(auto i : preorderTraversal(root)) {
        cout << i << ' ';
    }
    return 0;
}