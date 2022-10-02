/* https://leetcode.cn/problems/number-of-islands/ */
#include "LC.h"

// 图论经典题 岛屿数量，岛屿周长会做这题也会做
class Solution {
public:
    // dfs
    inline void dfs(vector<vector<char>> &grid, int r, int c) {
        // 越界返回结束该层递归
        if(!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size())) {
            return;
        }
        // 当前格不为岛屿或已经遍历过直接返回结束该层递归
        if(grid[r][c] != '1') {
            return;
        }
        // 当前格为岛屿则将其改为2代表已遍历过
        grid[r][c] = '2';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
    inline int numIslands(vector<vector<char>> &grid) {
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == '1') {
                    ++ans;
                    dfs(grid, r, c);
                }
            }
        }
        return ans;
    }
private:
    int ans = 0;
};

int main() {
    vector<vector<char>> grid{{'1','1','1','1','0'},
                              {'1','1','0','1','0'},
                              {'1','1','0','0','0'},
                              {'0','0','0','0','0'}};
    Solution solution;
    cout << solution.numIslands(grid);
    return 0;
}