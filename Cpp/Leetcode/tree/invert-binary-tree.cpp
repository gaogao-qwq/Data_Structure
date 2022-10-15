/* https://leetcode.cn/problems/invert-binary-tree/ */
#include "LCBinaryTree.h"

// 解法1：递归 前序遍历
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        // 保存右子树
        auto rightTree = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(rightTree);
        return root;
    }
};

int main() {
    Solution1 s1;
    vector<TreeNodePtr> input{4,2,7,1,3,6,9};
    auto root = generateTree(input);
    auto ans = s1.invertTree(root);
    return 0;
}