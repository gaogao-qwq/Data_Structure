#include "LC.h"

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101] = {0.0};
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i][j] >= 1) {
                    double remain = dp[i][j] - 1;
                    dp[i][j] = 1;
                    dp[i + 1][j] += remain / 2, dp[i + 1][j + 1] += remain / 2;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};

int main() {
    Solution s;
    cout << s.champagneTower(2, 1, 1);
    return 0;
}