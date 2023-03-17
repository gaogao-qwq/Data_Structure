#include <bits/stdc++.h>
using namespace std;

// 高精加法
void add(vector<int> &a, vector<int> &b) {
    // 进位
    int carry = 0;
    for (int i = 1; i <= 1000; i++) {
        b[i] += a[i] + carry;
        carry = b[i] / 10;
        b[i] %= 10;
    }
}

// 因为 1<=n<=50 所以只需要一个高精形参
void mul(vector<int> &a, int b) {
    // 进位
    int carry = 0;
    for (int i = 1; i <= 1000; i++) {
        a[i] = a[i] * b + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main() {
    vector<int> num(1001);
    vector<int> factor(1001);
    vector<int> sum(1001);
    int n;

    cin >> n;
    num[1] = 1;
    for (int i = 1; i <= n; i++) {
        mul(num, i);
        add(num, factor);
    }
    bool flag = false;
    for (int i = 1000; i >= 1; i--) {
        if (factor[i] != 0) flag = true;
        if (flag) cout << factor[i];
    }
    return 0;
}