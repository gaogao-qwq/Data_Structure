/* https://codeforces.com/problemset/problem/231/A */
#include <iostream>
using namespace std;

int main(void) {
    int n = 0, cnt = 0;
    int temp[3];
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> temp[0] >> temp[1] >> temp[2];
        if(temp[0] + temp[1] + temp[2] >= 2) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}