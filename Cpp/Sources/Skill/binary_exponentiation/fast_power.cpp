#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;
using ll = long long;


ll power(long a, long b) {
    // 朴素幂运算，一个一个乘，时间复杂度为 O(n)
    for(int i = 0; i < b; ++i) {
        a = (a * a) % MOD;
    }
    return a;
}

// 快速幂 O(logn)
ll binPower(long a, long b) {
    ll ans = 1;
    // 当 b 不为0（代表二进制数未枚举完）
    while(b > 0) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        // b 右移一位，枚举二进制数下一位
        b >>= 1;
    }
    return ans % MOD;
}

int main() {
    auto t1 = chrono::steady_clock::now();
    cout << power(7,31) << endl;
    auto t2 = chrono::steady_clock::now();
    cout << chrono::duration<double, std::micro>(t2 - t1).count() << endl;

    t1 = chrono::steady_clock::now();
    cout << binPower(7, 31) << endl;
    t2 = chrono::steady_clock::now();
    cout << chrono::duration<double, std::micro>(t2 - t1).count() << endl;
    return 0;
}