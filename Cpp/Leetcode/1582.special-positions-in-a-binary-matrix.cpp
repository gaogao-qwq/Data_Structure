// https://leetcode.cn/problems/special-positions-in-a-binary-matrix/
// 数组 矩阵
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> rowsSum(rows);
        vector<int> colsSum(cols);
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j){
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j){
                if(mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> mat{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << solution.numSpecial(mat) << endl;
    return 0;
}
