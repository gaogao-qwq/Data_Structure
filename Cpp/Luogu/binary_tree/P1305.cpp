/* https://www.luogu.com.cn/problem/P1305 */
#include <bits/stdc++.h>
using namespace std;

// 用字符串模拟二叉树前序遍历
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 2; i <= n; ++i) {
        string subt;
        cin >> subt;
        int index = s.find(subt[0]); // 找到这个子树的根节点在原串中的位置
        s.erase(index, 1);         // 清除根节点
        s.insert(index, subt);       // 加入子树
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '*') cout << s[i]; // 跳过空节点输出
    }
    return 0;
}