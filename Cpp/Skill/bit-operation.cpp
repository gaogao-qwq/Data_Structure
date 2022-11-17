#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    // 判断奇偶
    if(n & 1) cout << "n是奇数" << endl;
    else cout << "n是偶数" << endl;

    // 实现乘除法
    n = 3;
    cout << "n * 2 = " << (n << 1) << endl
         << "n / 2 = " << (n >> 1) << endl;

    // 实现交换两数
    int a = 3, b = 4;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << endl
         << "b = " << b << endl;
    
    // 交换符号
    n = -5;
    cout << n << " 的相反数为：" << ~n + 1 << endl;
    
    // 二进制逆序
    // 数34520的二进制表示：10000110 11011000
    // 逆序后则为：00011011 01100001 它的十进制为7009
    unsigned short u = 34520;
    cout << "u = " << u << endl;
    u = ((u & 0xAAAA) >> 1) | ((u & 0x5555) << 1);
    u = ((u & 0xCCCC) >> 2) | ((u & 0x3333) << 2);
    u = ((u & 0xF0F0) >> 4) | ((u & 0x0F0F) << 4);
    u = ((u & 0xFF00) >> 8) | ((u & 0x00FF) << 8);
    cout << "u = " << u << endl;

    // 统计二进制中 1 的个数
    // 34520 = 10000110 11011000
    u = 34520;
    int cnt = 0;
    while(u) {
        u = u & (u - 1);
        ++cnt;
    }
    cout << "十进制数34520转为二进制数后1的个数：" << cnt << endl;

    return 0;
}