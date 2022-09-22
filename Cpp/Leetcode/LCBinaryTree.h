/* https://zhuanlan.zhihu.com/p/547639030 */
#include "LC.h"

//使用LeetCode上树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//定义一个树指针类，方便释放内存
class TreeNodePtr {
private:
    TreeNode* node;
public:
    // 默认构造函数
    TreeNodePtr() :node(nullptr) {}
    // 构造函数1
    TreeNodePtr(int val) {
        node = new TreeNode(val);
    }
    // 复制构造函数（很必要，方便临时对象的复制）
    TreeNodePtr(const TreeNodePtr& t) {
        if (t.node == nullptr)
        {
            node = nullptr;
            return;
        }
        node = new TreeNode(t.node->val);
    }
    // 构造函数2（为了能用nullptr进行构造而定义）
    TreeNodePtr(TreeNode* n) : node(n) {}
    // 析构函数，释放内存
    ~TreeNodePtr() {
        delete node;
    }

    // 对外接口，返回节点指针
    TreeNode* getNodePtr()const {
        return node;
    }
};

// 生成二叉树
TreeNode* generateTree(const std::vector<TreeNodePtr>& input)
{
    if (input.empty()) {
        return nullptr;
    }

    std::queue<TreeNode*> que;
    TreeNode* node = input[0].getNodePtr();
    que.push(node);
    TreeNode* ans = node;
    int index = 0;
    int vecSize = input.size();

    while (!que.empty() && index < vecSize) {
        int size = que.size();
        int i = 0;
        while(i < size && index < vecSize) {
            node = que.front();
            que.pop();
            ++i;

            ++index;
            if (index >= vecSize) {
                break;
            }
            node->left = input[index].getNodePtr();
            if (node->left) {
                que.push(node->left);
            }
            
            ++index;
            if (index >= vecSize) {
                break;
            }
            node->right = input[index].getNodePtr();
            if (node->right) {
                que.push(node->right);
            }
        }
    }
    return ans;
}