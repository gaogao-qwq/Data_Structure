/* https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/ */
#include "LC.h"
#include "LCBinaryTree.h"

void flatten(TreeNode* root) {
    while(root != nullptr) {
        // 左子树为空直接考虑下一右结点
        if(root->left == nullptr) {
            root = root->right;
        } else {
            auto prev = root->left;
            // 遍历至左子树最右结点
            while(prev->right != nullptr) {
                prev = prev->right;
            }
            // 将原来的右子树接到上面遍历到的左子树最右结点
            prev->right = root->right;
            // 将左子树接到原来右子树的结点
            root->right = root->left;
            root->left = nullptr;
            // 进入下一右结点
            root = root->right;
        }
    }
}

int main() {
    vector<TreeNodePtr> input{1,2,5,3,4,nullptr,6};
    TreeNode *root = generateTree(input);
    flatten(root);
    return 0;
}