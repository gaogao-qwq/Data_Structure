/* https://www.luogu.com.cn/problem/P1059 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n(0);
    cin >> n;
    vector<int> arr;
    unordered_set<int> uset;
    for (int i = 0; i < n; ++i) {
        int tmp(0);
        cin >> tmp;
        if (uset.find(tmp) == uset.end()) {
            uset.emplace(tmp);
            arr.push_back(tmp);
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}