#include <bits/stdc++.h>
using namespace std;

// 题目只要求高精度除单精度，且要整数商。
void div(vector<int> a, int b, vector<int> &c) {
    int lena = 0, lenb = 0, tmp = b;
    while (tmp) {
        ++lenb;
        tmp /= 10;
    }
    for (lena = 5000; lena >= 0; --lena) {
        if (a[lena] != 0) break;
    }
    int last = lena - lenb;
}

int main() {
    vector<int> a(5001, 0), c(5001, 0);
    string s;
    int b(0);
    cin >> s >> b;
    if (stoi(s) < b || stoi(s) == 0) cout << 0;
    for (int i = 0; i < s.length(); ++i) {
        a[s.length() - i - 1] = s[i] - '0';
    }
    div(a, b, c);
    bool flag = false;
    for(int i = 5000; i >= 0; --i) {
        if (c[i] != 0) flag = true;
        if (flag) cout << c[i];
    }
    return 0;
}