/* https://leetcode.cn/problems/merge-two-binary-trees/ */
#include "LCBinaryTree.h"

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 遍历终止条件
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        // 不去创建新树来储存结果，直接用已有的tree1来存合并后的树
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }

int main() {
    vector<TreeNodePtr> input1{1,3,2,5};
    vector<TreeNodePtr> input2{2,1,3,nullptr,4,nullptr,7};
    auto root1 = generateTree(input1);
    auto root2 = generateTree(input2);
    auto root = mergeTrees(root1, root2);
    return 0;
}