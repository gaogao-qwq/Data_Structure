/* https://leetcode.cn/problems/set-matrix-zeroes/ */
#include "LC.h"

    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> loc;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    loc.push_back(make_pair(i, j));
                }
            }
        }
        for(auto i : loc) {
            for(int r = 0; r < matrix.size(); ++r) {
                matrix[r][i.second] = 0;
            }
            for(int c = 0; c < matrix[0].size(); ++c) {
                matrix[i.first][c] = 0;
            }
        }
    }

int main() {
    vector<vector<int>> matrix{{1,1,1},
                               {1,0,1},
                               {1,1,1}};
    setZeroes(matrix);
    for(auto i : matrix) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}