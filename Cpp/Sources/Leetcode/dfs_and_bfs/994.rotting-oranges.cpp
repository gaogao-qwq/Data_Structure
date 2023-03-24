/* https://leetcode.cn/problems/rotting-oranges/ */
#include "LC.h"

class Solution {
public:
    // 因为出发点不唯一（腐烂的橘子不唯一），且要求的不是腐烂的橘子的数量
    // 所以只能用 bfs
    inline int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int cnt = 0, ans = -1;
        // 遍历网格，将所有腐烂的橘子的位置推入队列
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 2) {
                    que.push(make_pair(r, c));
                    grid[r][c] = 3;
                }
                if(grid[r][c] == 1) {
                    ++cnt;
                }
            }
        }
        // 若没有新鲜的橘子直接返回0
        if(cnt == 0) return 0;
        // 若没有腐烂的橘子直接返回-1
        if(que.empty()) return -1;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                // 将队列的头部节点推出
                pair<int, int> curr = que.front();
                que.pop();
                // 遍历 curr 的所有相邻节点
                for(int i = 0; i < 4; ++i) {
                    int r = curr.first + direction[i][0];
                    int c = curr.second + direction[i][1];
                    // 判断该节点是否有效（不越界，值为1）且未访问过
                    if(!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size()) || grid[r][c] == 3 || grid[r][c] == 0) {
                        continue;
                    }
                    // 已遍历过的节点设为3
                    grid[r][c] = 3;
                    --cnt;
                    que.push(make_pair(r, c));
                }
            }
            ++ans;
        }
        // 若新鲜橘子数量为0，则返回时间，否则返回-1
        if(!cnt) return ans;
        return -1;
    }
private:
    vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};
};

int main() {
    Solution solution;
    vector<vector<int>> grid{{2,1,1},
                             {1,1,0},
                             {0,1,1}};
    cout << solution.orangesRotting(grid);
    return 0;
}
