#include <bits/stdc++.h>
using namespace std;

int L = 0, R = 0, ans = 0;

int main(int argc, char *argv[]) {
    cin >> L >> R;
    for (int i = L; i <= R; ++i) {
        if (!(i & 1) && i % 4) continue;
        ++ans;
    }
    cout << ans;
}