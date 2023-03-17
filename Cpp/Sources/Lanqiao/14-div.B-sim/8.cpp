#include <bits/stdc++.h>
using namespace std;

int time_cal(string t2, string t1) {
    return (stoi(t2.substr(0, 2)) - stoi(t1.substr(0, 2))) * 3600 + (stoi(t2.substr(3, 2)) - stoi(t1.substr(3, 2))) * 60 + stoi(t2.substr(6, 2)) - stoi(t1.substr(6, 2));
}

int main() {
    int n = 0;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<string> list(n);
    vector<int> U(n), I(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i] >> U[i] >> I[i];
    }
    int w = 0;
    for (int i = 1; i < n; ++i) {
        w += U[i - 1] * I[i - 1] * time_cal(list[i], list[i - 1]);
    }
    cout << w;
    return 0;
}