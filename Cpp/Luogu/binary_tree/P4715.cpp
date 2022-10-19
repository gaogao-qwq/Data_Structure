/* https://www.luogu.com.cn/problem/P4715 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n(0);
    cin >> n;
    vector<pair<int, int>> prev(pow(2, n));
    for (int i = 0; i < pow(2, n); ++i) {
        prev[i].first = i + 1;
        cin >> prev[i].second;
    }
    for (int i = n; i > 1; --i) {
        vector<pair<int, int>> vec;
        for (int j = 0; j < prev.size(); j += 2) {
            vec.push_back((prev[j].second > prev[j + 1].second) ? prev[j] : prev[j + 1]);
        }
        prev = vec;
        --n;
    }
    cout << ((prev[0].second < prev[1].second) ? prev[0].first : prev[1].first);
    return 0;
}