/* https://leetcode.cn/problems/island-perimeter/ */
#include "LC.h"

// 图论经典题 岛屿周长 
class Solution {
public:
    // dfs 解法
    inline void dfs(vector<vector<int>> &grid, int r, int c) {
        // 每当从一个岛屿格走向网格边界，周长加一
        if(!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size())) {
            ++ans;
            return;
        }
        // 每当从一个岛屿格走向水域格，周长加一
        if(grid[r][c] == 0) {
            ++ans;
            return;
        }
        // 若坐标所对应格不是岛屿或者已经遍历过，直接返回
        if(grid[r][c] != 1) {
            return;
        }
        // 将已遍历过的坐标对应值设为2
        grid[r][c] = 2;
        // 当前格向上一格递归
        dfs(grid, r - 1, c);
        // 当前格向下一格递归
        dfs(grid, r + 1, c);
        // 当前格向左一格递归
        dfs(grid, r, c - 1);
        // 当前格向右一格递归
        dfs(grid, r, c + 1);
    }
    inline int islandPerimeter(vector<vector<int>> &grid) {
        // 由于题目说明只有一个岛屿，直接遍历网格找到值为1的那格的坐标即可
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 1) {
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
    Solution solution;
    vector<vector<int>> grid{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << solution.islandPerimeter(grid);
    return 0;
}