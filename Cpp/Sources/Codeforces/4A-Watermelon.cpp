/* https://codeforces.com/problemset/problem/4/A */
#include <iostream>
using namespace std;

int main(void) {
    int w = 0;
    cin >> w;
    for(int i = 1; i < w; ++i) {
        if(!(i % 2) && !((w - i) % 2)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}