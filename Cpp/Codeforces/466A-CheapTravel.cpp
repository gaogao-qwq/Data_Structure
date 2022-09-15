/* https://codeforces.com/problemset/problem/466/A */
#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n = 0, m = 0, p1 = 0, p2 = 0;
    cin >> n >> m >> p1 >> p2;
    if(n < m) {
        if(p1 * n >= p2) {
            cout << p2;
        } else {
            cout << p1 * n;
        }
        return 0;
    }
    if(p1 >= p2) {
        cout << (int)ceil(n / (float)m) * p2;
    } else {
        if(p2 / m >= p1) {
            cout << p1 * n;
        } else {
            cout << (n / m) * p2 + n % m * p1;
        }
    }
    return 0;
}