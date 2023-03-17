#include "LCBinaryTree.h"

// 思考过程代码
bool traversal(TreeNode *node, int count) {
    // 若根节点为空直接返回 false
    if(node == nullptr) return false;
    // 终止条件：遍历至叶子结点为止，count 为0则返回 true，不为0则返回 false
    if(node->left == nullptr && node->right == nullptr && count == 0) {
        return true;
    }
    if(node->left == nullptr && node->right == nullptr && count != 0) {
        return false;
    }
    // 向左遍历实现
    if(node->left != nullptr) {
        count -= node->left->val;
        // 一旦递归返回 true，直接将 true 向上返回
        if(traversal(node->left, count)) {
            return true;
        }
        // 若不为 true，则进行回溯，将刚刚减去的值加回来
        count += node->left->val;
    }
    // 向右遍历实现
    if(node->right != nullptr) {
        count -= node->right->val;
        // 一旦递归返回 true，直接将 true 向上返回
        if(traversal(node->left, count)) {
            return true;
        }
        // 若不为 true，则进行回溯，将刚刚减去的值加回来
        count += node->left->val;
    }
    // 全部结点遍历完后未返回true，直接返回false
    return false;
}

// 简化代码
bool hasPathSum(TreeNode *root, int targetSum) {
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

int main() {
    vector<TreeNodePtr> input{5,4,8,11,nullptr,13,4,7,2,nullptr,nullptr,nullptr,1};
    auto root = generateTree(input);
    cout << "思考过程代码：" << boolalpha << traversal(root, 22) << endl;
    cout << "精简版代码：" << boolalpha << hasPathSum(root, 22) << endl;
    return 0;
}