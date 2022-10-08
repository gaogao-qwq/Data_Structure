/* https://leetcode.cn/problems/reshape-the-matrix/ */
#include "LC.h"

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int k = 0, l = 0;
        for(auto i : mat) {
            for(auto j : i) {
                if(l >= c) {
                    l = 0;
                    ++k;
                }
                ans[k][l] = j;
                ++l;
            }
        }
        return ans;
    }

int main() {
    return 0;
}