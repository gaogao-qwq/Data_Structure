// 10. 最小下标

// 问题描述

// 小蓝有一个由大写字母 ABCDEF 组成的字符串 S ，长度为 n，字符串的下标依次为 0 到 n-1 。
// 小蓝按照如下方法生成一个无限长的字符串：
// 首先选定一个 0 到 n-1 之间的数，作为初始下标。
// 从初始下标开始，将下标对应的字符加入到字符串的结尾，将字符的序号（A到F依次对应 1 到 6 ）与下标相加作为新的下标值，如果下标大于等于 n，将其对 n 求余。重复此过程，即得到无限长的字符串。
// 例如，对于字符串 ACDF，当初始下标是 0 时，生成的字符串为：ACACACACAC…
// 再如，对于字符串 DCBA，当初始下标是 1 时，生成的字符串为：CDDDDDDDDD…
// 给定小蓝的字符串 S，请问当初始下标为多少时，生成的字符串最小。

// 输入格式
// 输入一行包含一个字符串。

// 输出格式
// 输出一行，包含一个整数，为所求的下标，如果有多个下标满足要求，输出最小的那个。

// 样例输入1
// DCBA

// 样例输出1
// 3

// 样例输入2
// AAAA

// 样例输出2
// 0

// 评测用例规模与约定
// 令 |S| 表示 S 的长度。
// 对于 30% 的评测用例，1 <= |S| <= 100。
// 对于 50% 的评测用例，1 <= |S| <= 1000。
// 对于 70% 的评测用例，1 <= |S| <= 10000。
// 对于 80% 的评测用例，1 <= |S| <= 100000。
// 对于 100% 的评测用例，1 < = ∣S∣ < = 1000000。

#include <bits/stdc++.h>
using namespace std;

string str;
int n;
bool vis[1000005];

int inline getNext(int i) {
    return (i + str[i] - 'A' + 1) % n;
}

int main() {
    cin >> str;
    n = str.size();
    for (int i = 0; i < 1e6 + 5; i++)
        vis[i] = false;
    int i = 0, j = 1, len = 0, _i = 0, _j = 1;
    vis[0] = true, vis[1] = true;
    while (i < n && j < n && len < n) {
        int t = str[_i] - str[_j];
        if (!t) {
            _i = getNext(_i);
            _j = getNext(_j);
            len++;
        } else {
            if (t > 0) {
                int temp = i;
                while (temp != _i) {
                    vis[temp] = true;
                    temp = getNext(temp);
                }
                while (vis[i]) i++;
                vis[i] = true;
            } else {
                int temp = j;
                while (temp != _j) {
                    vis[temp] = true;
                    temp = getNext(temp);
                }
                while (vis[j]) j++;
                vis[j] = true;
            }
            _i = i, _j = j;
        }
    }
    cout << min(i, j);
    return 0;
}