/* https://codeforces.com/problemset/problem/1352/C */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int t = 0;
    cin >> t;
    vector<int> n(t), k(t);
    for(int i = 0; i < t; ++i) {
        cin >> n[i] >> k[i];
    }
    for(int i = 0; i < t; ++i) {
        int j = n[i], cnt = 1;
        while(true) {
            if(cnt + 1 == (int)ceil(k[i] / (float)(n[i] - 1))) {
                int temp = cnt * (n[i] - 1);
                while(temp != k[i]) {
                    ++temp;
                    ++j;
                }
                cout << j << endl;
                break;
            }
            j += n[i];
            ++cnt;
        }
    }
    return 0;
}