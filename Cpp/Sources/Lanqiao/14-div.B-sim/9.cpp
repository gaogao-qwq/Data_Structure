#include <bits/stdc++.h>
using namespace std;

// AAAAAAA
// ALLLLLA
// ALQQLAA
// ALQLAAC
// ALLAACC
// ALAACCC

int cnt = 0;

void traversal(vector<vector<char>> matrix, int r, int c, char p) {
    // left-up
    for (int a = 1; r - a >= 0 && c - a >= 0; ++a) {
        if (matrix[r - a][c] != p || matrix[r][c - a] != p) break;
        int b = a - 1;
        bool flag = true;
        while (b) {
            if (matrix[r - a + b][c - b] != p) flag = false;
            --b;
        }
        if (flag) ++cnt;
    }
    // right-down
    for (int a = 1; r + a < matrix.size() && c + a < matrix[0].size(); ++a) {
        if (matrix[r + a][c] != p || matrix[r][c + a] != p) break;
        int b = a - 1;
        bool flag = true;
        while (b) {
            if (matrix[r + a - b][c + b] != p) flag = false;
            --b;
        }
        if (flag) ++cnt;
    }
    // left-down
    for (int a = 1; r + a < matrix.size() && c - a >= 0; ++a) {
        if (matrix[r + a][c] != p || matrix[r][c - a] != p) break;
        int b = a - 1;
        bool flag = true;
        while (b) {
            if (matrix[r + a - b][c - b] != p) flag = false;
            --b;
        }
        if (flag) ++cnt;
    }
    // right-up
    for (int a = 1; r - a >= 0 && c + a < matrix[0].size(); ++a) {
        if (matrix[r - a][c] != p || matrix[r][c + a] != p) break;
        int b = a - 1;
        bool flag = true;
        while (b) {
            if (matrix[r - a + b][c + b] != p) flag = false;
            --b;
        }
        if (flag) ++cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            traversal(matrix, i, j, matrix[i][j]);
        }
    }
    cout << cnt;
    return 0;
}