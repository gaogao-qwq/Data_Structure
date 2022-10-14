#include <iostream>
using namespace std;

long long binPower(long long a, long long b, long long p) {
    long long ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    long long a(0), b(0), p(0);
    cin>>a>>b>>p;
    cout << a << "^" << b << " mod " << p << "=" << binPower(a,b,p);
    return 0;
}