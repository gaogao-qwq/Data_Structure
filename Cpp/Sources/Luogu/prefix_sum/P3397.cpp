#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    int mat[n][n] = {};
    for (int i = 0; i < m; ++i) {
        int startRow = 0, startCol = 0, endRow = 0, endCol = 0;
        scanf("%d%d%d%d", &startRow, &startCol, &endRow, &endCol);
        for (int j = startRow; j <= endRow; ++j) {
            for (int k = startCol; k <= endCol; ++k) {
                ++mat[j - 1][k - 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}