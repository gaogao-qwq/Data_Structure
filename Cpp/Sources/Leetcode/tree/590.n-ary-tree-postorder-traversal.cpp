/* https://leetcode.cn/problems/n-ary-tree-preorder-traversal/ */
#include "LCNaryTree.h"

class Solution {
public:
    // 类比2叉树的后序遍历 递归
    vector<int> recursionPostorder(Node* root) {
        if(root == nullptr) return ans;
        for(auto child : root->children) {
            recursionPostorder(child);
        }
        ans.push_back(root->val);
        return ans;
    }
    // TODO：非递归解法
    vector<int> postorder(Node* root) {
        if(root == nullptr) return ans;
        stack<Node *> stk;
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
    for(auto i : solution.postorder(root)) {
        cout << i << " ";
    }
    return 0;
}