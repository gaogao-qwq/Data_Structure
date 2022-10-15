/* https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/ */
#include "LC.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    inline Node* connect(Node* root) {
        if(root == nullptr) return root;
        deque<Node *> que;
        // 根节点推入队列
        que.push_back(root);
        auto p = root;
        while(!que.empty()) {
            int size = que.size();
            // 将队列中的首位存起来
            auto curr = que.front();
            // 将队列中的元素串联起来
            for(int i = 1; i < size; ++i) {
                curr->next = que[i];
                curr = que[i];
            }
            // 遍历队列中的每个元素，将每个元素的左右节点也放入队列中
            for(int i = 0; i < size; ++i) {
                curr = que.front();
                que.pop_front();
                if(curr->left != nullptr) {
                    que.push_back(curr->left);
                }
                if(curr->right != nullptr) {
                    que.push_back(curr->right);
                }
            }
        }
        return root;
    }
};

int main() {
    Solution solution;
    auto root = new Node(1, new Node(2, new Node(4), new Node(5), NULL), new Node(3, new Node(6), new Node(7), NULL), NULL);
    auto ans = solution.connect(root);
    return 0;
}