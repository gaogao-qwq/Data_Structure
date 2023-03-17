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

/**
 * 竖式长除法实际上可以看作一个逐次减法的过程
 * 与其它三则运算不同，竖式除法我们是从最高位到最低位做运算
 * 所以需要从后往前遍历高精度数 a 和 b 分别找到被除数和除数的长度 la lb
 */

// greater_eq() 用于判断被除数以下标 last_dg 为最低位，是否可以再减去除数而保持非负
// 形参分别为：被除数 除数 被除数最低位下标 除数长度
inline bool greater_eq(vector<int> a, vector<int> b, int last_dg, int len) {
    // 有可能被除数剩余的部分比除数长，这个情况下最多多出 1 位，故如此判断即可
    if (a[last_dg + len] != 0) return true;
    // 从高位到低位，逐位比较
    for (int i = LEN; i >= 0; --i) {
        // 被除数以下标 last_dg 为最低位大于除数，可减去
        if (a[last_dg + i] > b[i]) return true;
        // 被除数以下标 last_dg 为最低位小于除数，不可减去
        if (a[last_dg + i] < b[i]) return false;
    }
    // 相等也可以减去
    return true;
}

// 形参分别为：被除数 除数 商 余数
void div(vector<int> a, vector<int> b, vector<int> &c, vector<int> &d) {
    clear(c), clear(d);

    // 从后往前遍历得到被除数和除数的长度 la lb
    int la(0), lb(0);
    for (la = LEN - 1; la > 0; --la) {
        if (a[la - 1] != 0) break;
    }
    for (lb = LEN - 1; lb > 0; --lb) {
        if (b[lb - 1] != 0) break;
    }
    // 除数为0，数据非法，直接返回
    if (lb == 0) {
        cout << "Illegal num";
        return;
    }

    // d 是被除数剩余部分，函数结束后理所应当为余数
    for (int i = 0; i < la; ++i) {
        d[i] = a[i];
    }
    for (int i = la - lb; i >= 0; --i) {
        while (greater_eq(d, b, i, lb)) {
            // 若可以减，则减
            // 此处为高精度减法
            for (int j = 0; j < lb; ++j) {
                d[i + j] -= b[j];
                // 借位
                if (d[i + j] < 0) {
                    --d[i + j + 1];
                    d[i + j] += 10;
                }
            }
            // 商的第i位自增1
            ++c[i];
        }
    }
}

int main() {
    vector<int> a(1000, 0), b(1000, 0), c(1000, 0), d(1000, 0);
    read(a), read(b);
    // 被除数小于除数，直接输出0
    if (a < b) {
        cout << 0;
    }
    div(a, b, c, d);
    print(c);
    return 0;
}