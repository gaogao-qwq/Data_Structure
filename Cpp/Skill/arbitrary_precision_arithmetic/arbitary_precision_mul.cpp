#include <bits/stdc++.h>
using namespace std;

// 开数组长度为1000，不够再加
const int LEN = 1000;

// 高精度数置0
void clear(vector<int> &a) {
    for (auto &i : a) i = 0;
}

// 从 stdin 读入高精度数函数
void read(vector<int> &a) {
    // 置0
    clear(a);

    string s;
    cin >> s;
    // 由于一般我们习惯称第一位为最高位，所以要把从stdin中读取到的string逆序存储在数组中
    for (int i = 0; i < s.length(); ++i) {
        a[s.length() - i - 1] = s[i] - '0';
    }
}

// 打印高精度数函数（由于存储高精度数时是逆序存的，所以打印也需要逆序打印）
void print(vector<int> a) {
    // 定义一个布尔变量用于忽略前导0
    bool flag = false;
    for (int i = LEN - 1; i >= 0; --i) {
        if (a[i] != 0) flag = true;
        if (flag) cout << a[i];
    }
    cout << endl;
}

// 高精度数 * 高精度数
void mul(vector<int> a, vector<int> b, vector<int> &c) {
    clear(c);

    for(int i = 0; i < LEN - 1; ++i) {
        for(int j = 0; j <= i; ++j) {
            c[i] += a[j] * b[i - j];
        }
        if(c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] % 10;
        }
    }
}

int main() {
    vector<int> a(1000, 0), b(1000, 0), c(1000, 0);
    read(a), read(b);
    mul(a, b, c);
    print(c);
    return 0;
}