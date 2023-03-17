/* https://codeforces.com/problemset/problem/158/A */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n = 0, k = 0, cnt = 0;
    cin >> n >> k;
    vector<int> scores(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    for(int i = 0; i < n; ++i) {
        if(scores[i] >= scores[k - 1] && scores[i] > 0) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}