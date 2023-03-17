/* https://www.luogu.com.cn/problem/P1030 */
#include <bits/stdc++.h>
using namespace std;

void traversal(string in, string post) {
    if (in.length() > 0) {
        char root = post[post.length() - 1];
        cout << root;
        int i = in.find(root);

        // 中序遍历左子树，后序遍历左子树的树
        string in_left = in.substr(0, i);
        string post_left = post.substr(0, i);
        traversal(in_left, post_left);
        
        // 中序遍历右子树，后序遍历右子树的树
        string in_right = in.substr(i + 1);
        string post_right = post.substr(i, post.length() - i - 1);
        traversal(in_right, post_right);
    }
}

int main() {
    string in, post;
    cin >> in >> post;
    traversal(in, post);
    return 0;
}