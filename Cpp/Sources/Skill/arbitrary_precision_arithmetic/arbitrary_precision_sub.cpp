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

void sub(vector<int> a, vector<int> b, vector<int> &c) {
    clear(c);

    for (int i = 0; i < LEN - 1; ++i) {
        // 对应位上数相减
        c[i] += a[i] - b[i];
        // 借位
        if (c[i] < 0) {
            --c[i + 1];
            c[i] += 10;
        }
    }
}

int main() {
    vector<int> a(LEN, 0), b(LEN, 0), c(LEN, 0);
    read(a), read(b);
    // 被减数与减数相等，输出0
    if(a == b) {
        cout << 0;
        return 0;
    }
    // 若减数大于被减数，可以根据运算法则 a - b = -(b - a) 进行处理
    for (int i = LEN - 1; i >= 0; --i) {
        if (a[i] < b[i]) {
            sub(b, a, c);
            cout << "-";
            print(c);
            break;
        }
        if (a[i] > b[i]) {
            sub(a, b, c);
            print(c);
            break;
        }
    }
    return 0;
}