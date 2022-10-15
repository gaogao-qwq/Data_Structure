/* https://www.lanqiao.cn/problems/217/learning/ */
// 动态规划 递推 矩阵快速幂
/* https://blog.csdn.net/weixin_46221946/article/details/119323609 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, p;
struct Matrix {
    ll m[3][3];
    Matrix() {m[1][1] = m[1][2] = m[2][1] = m[2][2] = 0;}
    Matrix(ll a, ll b, ll c, ll d) {
        m[1][1] = a;
        m[1][2] = b;
        m[2][1] = c;
        m[2][2] = d;
    }
};

ll mul(ll a, ll b, ll mod) {
    ll res = 0;
    while(b) {
        if(b & 1) res = (res + a) % mod;
        (a <<= 1) %= mod;
        b >>= 1;
    }
    return res;
    }

Matrix Matrix_mul(Matrix a, Matrix b, ll mod) {
    Matrix res;
    for(int i = 1; i <= 2; i++)
    for(int j = 1; j <= 2; j++)
    for(int k = 1; k <= 2; k++)
    res.m[i][j] = (res.m[i][j] + mul(a.m[i][k], b.m[k][j], mod)) % mod;
    return res;
}

ll Fib(ll n, ll mod) {
    Matrix res = Matrix(1, 0, 1, 0);
    Matrix a = Matrix(1, 1, 1, 0);
    while(n) {
        if(n & 1) res = Matrix_mul(res, a, mod);
        a = Matrix_mul(a, a, mod);
        n >>= 1;
    }
    return res.m[1][2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    // 如果m > n + 2，则S(n) = f(n+2)-1 < f(n+2) < f(m)，那无需对 f(m) 进行取模操作
    if(m > n + 2) cout << (Fib(n+2, p)  + p - 1) % p;
    else {
        // 得到f(m)，因为没法实现边进行矩阵快速幂边取模的操作，因此评测的数据必然能保证将f(m)求出来
        ll Fm = Fib(m, LONG_LONG_MAX); 
        cout << (Fib(n+2, Fm) + p - 1) % p;
    }
    return 0;
}