/**
 * 二叉搜索树（Binary Search Tree aka BST）是一种二叉树，其中每个结点最多有两个子结点
 * 且具有二叉搜索树性质：
 * 左子树上所有结点的值均小于它的根结点的值以及右子树上所有结点的值均大于它的根结点的值。
 * 
 * 题目要求：
 * 给你一个整数数组 nums，其中元素已经按升序排列，请你将其转换为一棵高度平衡二叉搜索树
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* build(int *nums, int left, int right) {
    if(left > right){
        return NULL;
    }

    int mid = (left + right) / 2;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return build(nums, 0, numsSize - 1);
}

int main(int argc, char **argv) {
    int nums[5] = {-10, -3, 0, 5, 9}, numsSize = 5;
    struct TreeNode *root = sortedArrayToBST(nums, numsSize);
    return 0;
}