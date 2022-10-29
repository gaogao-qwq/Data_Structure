/* https://www.luogu.com.cn/problem/P1216 */
// 简单 dp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int r = 0;
    cin >> r;
    if (r == 1) {
        int tmp = 0;
        cin >> tmp;
        cout << tmp << endl;
        return 0;
    }
    vector<vector<int>> mat(r, vector<int>(r));
    cin >> mat[0][0] >> mat[1][0] >> mat[1][1];
    mat[1][0] += mat[0][0];
    mat[1][1] += mat[0][0];
    for (int i = 2; i < r; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cin >> mat[i][j];
        }
        mat[i][0] += mat[i - 1][0];
        for (int j = 1; j < i + 1; ++j) {
            mat[i][j] = max(mat[i][j] + mat[i - 1][j - 1], mat[i][j] + mat[i - 1][j]);
        }
    }
    int ans = 0;
    for (auto i : mat[r - 1]) {
        ans = max(ans, i);
    }
    cout << ans << endl;
    return 0;
}