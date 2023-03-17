#include "LC.h"

class Solution {
public:
    // 一次 dfs 将第一个岛的所有值设为2 并且将第一个岛屿的节点全部入队列
    void dfs(vector<vector<int>> &grid, int r, int c) {
        // 递归终止条件
        if (grid[r][c] == 0 || grid[r][c] == 2) return;

        que.push(make_pair(r, c));
        grid[r][c] = 2;
        // left
        if (c - 1 >= 0 && grid[r][c - 1] == 1) dfs(grid, r, c - 1);
        // right
        if (c + 1 < grid[0].size() && grid[r][c + 1] == 1) dfs(grid, r, c + 1);
        // up
        if (r - 1 >= 0 && grid[r - 1][c] == 1) dfs(grid, r - 1, c);
        // down
        if (r + 1 < grid.size() && grid[r + 1][c] == 1) dfs(grid, r + 1, c);
    }

    // 一次 bfs 找到最近距离
    void bfs(vector<vector<int>> &grid) {
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                auto p = que.front();
                que.pop();
                int r = p.first, c = p.second;
                // 该 for 只负责控制 bfs 的方位控制
                for (int j = 0; j < 4; ++j) {
                    int x = c + dx[j], y = r + dy[j];
                    if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size()) continue;
                    if (grid[y][x] == 2) continue;
                    if (grid[y][x] == 1) return;
                    grid[y][x] = 2;
                    que.push(make_pair(y, x));
                }
            }
            ++ans;
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (!flag) {
                        dfs(grid, i, j);
                        flag = true;
                        continue;
                    }
                    bfs(grid);
                    return ans;
                }
            }
        }
        return ans;
    }
private:
    // 注意此处方位顺序为 "左右上下"
    vector<int> dx{-1, 1, 0, 0}, dy{0, 0, 1, -1};
    queue<pair<int, int>> que;
    int ans = 0;
};

int main() {
    vector<vector<int>> grid{{0,0,0,0,0,0},
                             {0,1,0,0,0,0},
                             {1,1,0,0,0,0},
                             {1,1,0,0,0,0},
                             {0,0,0,0,0,0},
                             {0,0,1,1,0,0}};
    Solution s;
    cout << s.shortestBridge(grid) << endl;
    return 0;
}