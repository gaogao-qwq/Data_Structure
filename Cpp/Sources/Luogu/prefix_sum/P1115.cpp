#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, tmp = 0, ans = INT32_MIN;
    cin >> n;
    int seq[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        if (i < 1)
            seq[i] = tmp;
        else
            seq[i] = max(seq[i - 1] + tmp, tmp);
        ans = max(seq[i], ans);
    }
    printf("%d", ans);
    return 0;
}