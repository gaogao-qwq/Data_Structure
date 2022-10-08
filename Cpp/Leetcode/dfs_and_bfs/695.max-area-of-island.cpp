/* https://leetcode.cn/problems/max-area-of-island/ */
#include "LC.h"

// 图论经典题 最大岛屿面积，岛屿周长会做这题也会做
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        // 越界终止递归
        if(!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size())) {
            return;
        }
        // 非岛屿或已遍历过终止递归
        if(grid[r][c] != 1) {
            return;
        }
        // 已遍历过的格子置为2代表已遍历过
        grid[r][c] = 2;
        ++tmp;
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 1) {
                    dfs(grid, r, c);
                    ans = max(ans, tmp);
                    tmp = 0;
                }
            }
        }
        return ans;
    }
private:
    int tmp = 0;
    int ans = 0;
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << solution.maxAreaOfIsland(grid);
    return 0;
}