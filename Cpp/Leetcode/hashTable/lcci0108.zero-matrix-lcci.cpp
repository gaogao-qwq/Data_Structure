/* https://leetcode.cn/problems/zero-matrix-lcci/ */
#include "LC.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> coord;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    coord.push_back(make_pair(i, j));
                }
            }
        }
        for(auto i : coord) {
            for(int r = 0; r < matrix.size(); ++r) {
                if(matrix[r][i.second] == 0) {
                    continue;
                }
                matrix[r][i.second] = 0;
            }
            for(int c = 0; c < matrix[0].size(); ++c) {
                if(matrix[i.first][c] == 0) {
                    continue;
                }
                matrix[i.first][c] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix{{1,1,1},
                               {1,0,1},
                               {1,1,1}};
    solution.setZeroes(matrix);
    return 0;
}