/* https://www.luogu.com.cn/problem/P2670 */
#include <bits/stdc++.h>
using namespace std;

void cnt(int r, int c, vector<vector<char>> &mat) {
    int n = mat.size(), m = mat[0].size();
    if(r - 1 >= 0 && c - 1 >= 0 && mat[r-1][c-1] != '*') {
        ++mat[r-1][c-1];
    }
    if(r - 1 >= 0 && mat[r-1][c] != '*') {
        ++mat[r-1][c];
    }
    if(r - 1 >= 0 && c + 1 < m && mat[r-1][c+1] != '*') {
        ++mat[r-1][c+1];
    }
    if(c - 1 >= 0 && mat[r][c-1] != '*') {
        ++mat[r][c-1];
    }
    if(c + 1 < m && mat[r][c+1] != '*') {
        ++mat[r][c+1];
    }
    if(r + 1 < n && c - 1 >= 0 && mat[r+1][c-1] != '*') {
        ++mat[r+1][c-1];
    }
    if(r + 1 < n && mat[r+1][c] != '*') {
        ++mat[r+1][c];
    }
    if(r + 1 < n && c + 1 < m && mat[r+1][c+1] != '*') {
        ++mat[r+1][c+1];
    }
}

int main() {
    int r(0),c(0);
    cin>>r>>c;
    vector<vector<char>> mat(r,vector<char>(c, '0'));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            char c = ' ';
            cin>>c;
            if(c == '*') {
                mat[i][j] = '*';
                cnt(i,j,mat);
            }
        }
    }
    for(auto i : mat) {
        for(auto j : i) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}