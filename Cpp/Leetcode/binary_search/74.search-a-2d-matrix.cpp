#include "LC.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            if (l == r || r == l + 1) {
                return matrix[l / n][l - l / n * n] == target || matrix[r / n][r - r / n * n] == target ? true : false;
            }
            int mid = (l + r) / 2;
            if (target == matrix[mid / n][mid - mid / n * n]) {
                return true;
            }
            if (target > matrix[mid / n][mid - mid / n * n]) {
                l = mid;
                continue;
            }
            r = mid;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Solution s;
    cout << boolalpha << s.searchMatrix(matrix, 3);
    return 0;
}