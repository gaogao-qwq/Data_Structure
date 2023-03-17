#include "LC.h"

// 错误解法 BFS
// struct loc{
//     char val;
//     int r;
//     int c;
//     loc(char _v, int _r, int _c) : val(_v), r(_r), c(_c) {};
// };

// class Solution {
// public:
//     void traversal(vector<string> &grid, int r, int c) {
//         // up
//         if (r - 1 >= 0 && grid[r - 1][c] != 'X' && grid[r - 1][c] != '#') { 
//             que.push(*new loc(grid[r - 1][c], r - 1, c));
//             grid[r - 1][c] = 'X';
//         }
//         // down
//         if (r + 1 < grid.size() && grid[r + 1][c] != 'X' && grid[r + 1][c] != '#') {
//             que.push(*new loc(grid[r + 1][c], r + 1, c));
//             grid[r + 1][c] = 'X';
//         }
//         // left
//         if (c - 1 >= 0 && grid[r][c - 1] != 'X' && grid[r][c - 1] != '#') {
//             que.push(*new loc(grid[r][c - 1], r, c - 1));
//             grid[r][c - 1] = 'X';
//         }
//         // right
//         if (c + 1 < grid[0].size() && grid[r][c + 1] != 'X' && grid[r][c + 1] != '#') {
//             que.push(*new loc(grid[r][c + 1], r, c + 1));
//             grid[r][c + 1] = 'X';
//         }
//         // 该点也要记作已遍历
//         grid[r][c] = 'X';
//     }

//     int shortestPathAllKeys(vector<string> &grid) {
//         // 先遍历一次图，获取总钥匙数量和起点。
//         int cnt = 0, startR = 0, startC = 0;
//         for (int i = 0; i < grid.size(); ++i) {
//             for (int j = 0; j < grid[0].size(); ++j) {
//                 if (grid[i][j] == '@') startR = i, startC = j;
//                 if (grid[i][j] >= 'a' && grid[i][j] <= 'z') ++cnt;
//             }
//         }
        
//         // BFS 队列初始化
//         traversal(grid, startR, startC);
//         // BFS
//         int ans = 0;
//         while (!que.empty()) {
//             int n = que.size();
//             for (int i = 0; i < n; ++i) {
//                 if (que.front().val >= 'a' && que.front().val <= 'z') {
//                     backpack.emplace(que.front().val);
//                     traversal(grid, que.front().r, que.front().c);
//                 }
//                 if (que.front().val >= 'A' && que.front().val <= 'Z' && backpack.find(que.front().val + 32) != backpack.end()) {
//                     traversal(grid, que.front().r, que.front().c);
//                 }
//                 if (que.front().val == '.') {
//                     traversal(grid, que.front().r, que.front().c);
//                 }
//                 que.pop();
//             }
//             ++ans;
//             if (backpack.size() == cnt) return ans;
//         }
//         return -1;
//     }
// private:
//     // 钥匙编号互不相同，造一个 uset 用来存钥匙
//     unordered_set<char> backpack;
//     queue<loc> que;
// };

// 正确解法：BFS + 状态压缩（位运算）
class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    struct State {
        int x;
        int y;
        int key;
    };
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // 先找到起点，以及钥匙的数量
        State start; 
        int keycnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start.x = i;
                    start.y = j;
                    start.key = 0;
                }
                if (islower(grid[i][j])) {
                    keycnt++;
                }
            }
        }
        
        // BFS
        queue<State> q;
        q.push(start);
        int allkey = (1 << keycnt) - 1; // 表示所有钥匙都找到的状态
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(allkey + 1, false)));
        int step = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                State cur = q.front();
                q.pop();
                
                // 如果所有钥匙都找到
                if (cur.key == allkey) return step;
                
                // 遍历下一个状态
                for (int k = 0; k < 4; k++) {
                    int x = cur.x + dx[k], y = cur.y + dy[k];
                    if (x < 0 || y < 0 || x >= m || y >= n) continue;
                    
                    char c = grid[x][y];
                    int key = cur.key;
                    
                    if (c == '#') continue;
                    if (isupper(c) && (key >> (c - 'A') & 1) == 0) continue;
                    
                    if (islower(c)) {
                        key |= 1 << (c - 'a');
                    }
                    if (visited[x][y][key] == true) continue;
                    
                    visited[x][y][key] = true; 
                    q.push(State{x, y, key}); 
                } 
            }
            step++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> grid{"@.a.#","###.#","b.A.B"};
    cout << s.shortestPathAllKeys(grid);
    return 0;
}