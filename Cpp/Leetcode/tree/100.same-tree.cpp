/* https://leetcode.cn/problems/same-tree/ */
#include <iostream>
#include "LCBinaryTree.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    if(p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void) {
    vector<TreeNodePtr> input1{1,2,3};
    vector<TreeNodePtr> input2{1,2,3};
    TreeNode *p = generateTree(input1);
    TreeNode *q = generateTree(input2);
    cout << isSameTree(p, q);
    return 0;
}