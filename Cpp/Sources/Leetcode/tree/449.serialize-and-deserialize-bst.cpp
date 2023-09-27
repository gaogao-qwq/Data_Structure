#include "LCBinaryTree.h"

class Codec {
public:
    string serialize(TreeNode *root) {
        if (root == nullptr) return "[]";
        queue<TreeNode *> que;
        string treeStr = "[" + to_string(root->val);
        string nullStr = "";
        que.push(root);
        while (!que.empty()) {
            if (que.front()->left != nullptr) {
                que.push(que.front()->left);
                treeStr.append(nullStr + "," + to_string(que.front()->left->val));
                nullStr.clear();
            } else {
                nullStr.append(",null");
            }
            if (que.front()->right != nullptr) {
                que.push(que.front()->right);
                treeStr.append(nullStr + "," + to_string(que.front()->right->val));
                nullStr.clear();
            } else {
                nullStr.append(",null");
            }
            que.pop();
        }
        treeStr.append("]");
        return treeStr;
    }

    TreeNode *deserialize(string data) {
        if (data == "[]") return nullptr;
        string node = "";
        vector<int> nodes;
        istringstream ss(data.substr(1, data.length() - 2));
        while (getline(ss, node, ',')) {
            if (node == "null") {
                nodes.push_back(-1);
                continue;
            }
            nodes.push_back(stoi(node));
        }
        TreeNode *root = new TreeNode(nodes[0]);
        queue<TreeNode *> que;
        que.push(root);
        for (int i = 0, j = 0; i < nodes.size(); ++i) {
            if (nodes[i] == -1) continue;
            int size = que.size();
            for (int k = 0; k < size; ++k) {
                if (++j >= nodes.size()) break;
                if (nodes[j] != -1) {
                    auto left = new TreeNode(nodes[j]);
                    que.front()->left = left;
                    que.push(left);
                }
                if (++j >= nodes.size()) break;
                if (nodes[j] != -1) {
                    auto right = new TreeNode(nodes[j]);
                    que.front()->right = right;
                    que.push(right);
                }
                que.pop();
            }
        }
        return root;
    }
};

int main() {
    Codec *ser = new Codec();
    Codec *deser = new Codec();
    vector<TreeNodePtr> input1{5, 2, 7, 1, 3, 6, 8, nullptr, nullptr, nullptr, 4};
    vector<TreeNodePtr> input2{5, 4, nullptr, 1, nullptr, nullptr, 2, nullptr, 3};
    vector<TreeNodePtr> input3{0};
    vector<TreeNodePtr> input4{2, 1};
    TreeNode *root = generateTree(input2);
    string str = ser->serialize(root);
    TreeNode *ans = deser->deserialize(str);
    cout << str << endl << ser->serialize(ans);
}