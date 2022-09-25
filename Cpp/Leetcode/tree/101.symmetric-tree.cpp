/* https://leetcode.cn/problems/symmetric-tree/ */
#include "LC.h"
#include "LCBinaryTree.h"

bool dfs(TreeNode *left, TreeNode *right) {
    // 递归的终止条件是两个节点都为空
    // 或者两个节点中有一个为空
    // 或者两个节点的值不相等
    if(left == nullptr && right == nullptr) {
        return true;
    }
    if(left == nullptr || right == nullptr) {
        return false;
    }
    if(left->val != right->val) {
        return false;
    }
    return dfs(left->left, right->right) && dfs(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return dfs(root->left, root->right);
}

int main() {
    vector<TreeNodePtr> input{ 1,2,2,nullptr,3,nullptr,3 };
    TreeNode *root = generateTree(input);
    cout << boolalpha << isSymmetric(root);
    return 0;
}