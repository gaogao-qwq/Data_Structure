#include "LC.h"

class Solution {
public:
    // 旋转矩阵：矩阵转置后镜像翻转即可
    // 矩阵转置：以矩阵主对角线为对称轴，翻转矩阵
    // 镜像反转：以矩阵第 n / 2 列为对称轴，翻转矩阵
    void rotate(vector<vector<int>>& matrix) {
        // 矩阵转置
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 镜像反转
        for (int i = 0; i < matrix.size() / 2; ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                swap(matrix[j][i], matrix[j][matrix.size() - i - 1]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}