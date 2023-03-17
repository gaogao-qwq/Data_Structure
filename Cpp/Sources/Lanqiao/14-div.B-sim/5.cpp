#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<int>> adj(100);

int inline sum(int a, int b, int c, int d) {
    int res = 0;
    for (int i = a; i < a + c; i++) {
        for (int j = b; j < b + d; j++) {
            res += adj[i][j];
        }
    }
    return res;
}

int main() {
    for (int i = 0; i < 100; i++) {
        adj[i].push_back(i + 1);
        for (int j = 1; j < 100; j++) {
            adj[i].push_back(adj[i][j - 1] + 2);
        }
    }
    int ans = 10001;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 1; k <= 100 - i; k++) {
                for (int l = 1; l <= 100 - j; l++) {
                    if (sum(i, j, k, l) == 2022) {
                        ans = min(ans, k * l);
                        break;
                    } else if (sum(i, j, k, l) > 2022) break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     for (int i = 1; i < 298; ++i) {
//         int sum = 0, cnt = 0;
//         for (int j = i; j < 298; ++j) {
//             sum += j, ++cnt;
//             if (sum == 2022) {
//                 cout << cnt << " ";
//             }
//         }
//     }
//     return 0;
// }