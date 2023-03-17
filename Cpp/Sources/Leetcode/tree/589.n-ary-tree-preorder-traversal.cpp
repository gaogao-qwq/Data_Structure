/* https://leetcode.cn/problems/n-ary-tree-preorder-traversal/ */
#include "LCNaryTree.h"

class Solution {
public:
    // 类比2叉树的前序遍历 递归
    vector<int> recursionPreorder(Node* root) {
        if(root == nullptr) return ans;
        ans.push_back(root->val);
        for(auto child : root->children) {
            recursionPreorder(child);
        }
        return ans;
    }
    // 使用栈的特点实现非递归前序遍历（其实就是bfs）
    vector<int> preorder(Node* root) {
        stack<Node *> stk;
        if(root == nullptr) return ans;
        stk.push(root);
        while(!stk.empty()) {
            auto node = stk.top();
            ans.push_back(node->val);
            stk.pop();
            for(int i = node->children.size() - 1; i >= 0; --i) {
                stk.push(node->children[i]);
            }
        }
        return ans;
    }
private:
    vector<int> ans;
};

int main() {
    auto root = new Node(1, vector<Node*>{new Node(3, vector<Node*>{new Node(5), new Node(6)}), new Node(2), new Node(4)});
    Solution solution;
    for(auto i : solution.preorder(root)) {
        cout << i << " ";
    }
    return 0;
}