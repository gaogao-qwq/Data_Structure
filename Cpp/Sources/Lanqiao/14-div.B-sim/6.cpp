#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t = 0, s = 0;
    cin >> s >> t;
    cout << (t < s ? 7 - s + t : t - s);
    return 0;
}