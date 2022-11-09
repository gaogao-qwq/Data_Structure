#include "LC.h"

// 这道题朴素想法是用 dfs 去搜索矩阵中每个元素 上下左右 四个方向连续1的最小值
// 但实际上这道题可以非常巧妙地使用 dp
// dp 做法：
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));

        for (int i = 0; i < mines.size(); ++i) {
            grid[mines[i][0]][mines[i][1]] = 0;
        }

        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            // left
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1;
                left[i][j] = cnt;
            }
            // right
            cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1;
                right[i][j] = cnt;
            }
        }

        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            // up
            for (int i = 0; i < n; ++i) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1;
                up[i][j] = cnt; 
            }
            // down
            cnt = 0;
            for (int i = n - 1; i >= 0; --i) {
                cnt = grid[i][j] == 0 ? 0 : cnt + 1;
                down[i][j] = cnt;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, min({up[i][j], down[i][j], left[i][j], right[i][j]}));
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<vector<int>> mines{{0,0},{0,1},{0,4},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{2,3},{2,4},{3,0},{4,0},{4,1},{4,3},{4,4}};
    cout << s.orderOfLargestPlusSign(5, mines);
    return 0;
}