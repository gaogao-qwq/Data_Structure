#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; ++i) que.push(i);
    int cnt = 0;
    while (!que.empty()) {
        if (++cnt == m) {
            cnt = 0;
            cout << que.front() << " ";
            que.pop();
            continue;
        }
        que.push(que.front());
        que.pop();
    }
    return 0;
}