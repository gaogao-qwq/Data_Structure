#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // vector<vector<int>> matrix(100, vector<int>(100));
    // matrix[0][0] = 1;
    // for (int i = 1; i < 100; ++i) {
    //     matrix[i][0] = i + 1;
    //     matrix[0][i] = matrix[0][i - 1] + 2;
    // }
    // for (int i = 1; i < 100; ++i) {
    //     for (int j = 1; j < 100; ++j) {
    //         matrix[i][j] = matrix[i][j - 1] + 2;
    //     }
    // }
    // int ans = INT32_MAX;
    // for (int i = 1; i <= 100; ++i) {
    //     for (int j = 2; j <= 100; ++j) {
    //         for (int startr = 0; startr < 100; ++startr) {
    //             for (int startc = 0; startc < 100; ++startc) {
    //                 int sum = 0;
    //                 for (int r = startr; startr + r < 100 && r - startr < i; ++r) {
    //                     for (int c = startc; startc + c < 100 && c - startc < j; ++c) {
    //                         sum += matrix[r][c];
    //                     }
    //                 }
    //                 if (sum == 2022 && i * j < ans) ans = i * j;
    //             }
    //         }
    //     }
    // }
    // for (int i = 0; i < 100; ++i) {
    //     for (int j = 0; j < 100; ++j) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << ans;


    
    for (int i = 1; i < 298; ++i) {
        int sum = 0, cnt = 0;
        for (int j = i; j < 298; ++j) {
            sum += j, ++cnt;
            if (sum == 2022) {
                cout << cnt << " ";
            }
        }
    }
    return 0;
}