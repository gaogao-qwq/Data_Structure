#include <iostream>
using namespace std;

int main() {
    int k = 0, n = 0, w = 0, cost = 0;
    cin >> k >> n >> w;
    for(int i = 1; i <= w; ++i) {
        cost += i * k;
    }
    cout << (n < cost ? cost - n : 0);
    return 0;
}