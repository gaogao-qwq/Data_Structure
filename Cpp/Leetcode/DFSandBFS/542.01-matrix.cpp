/* https://leetcode.cn/problems/01-matrix/ */
#include "LC.h"

// 经典BFS题 01矩阵
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> que;
        int row = mat.size(), col = mat[0].size();
        // 遍历矩阵，将所有0推入队列，将所有1设为-1
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(mat[i][j] == 0) {
                    que.push(make_pair(i, j));
                    continue;
                }
                mat[i][j] = -1;
            }
        }
        // 由于需要确定目前到了哪一层，需要定义一个 level 变量来判断层数
        int level = 1;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                // 将队列头部节点推出
                pair<int, int> curr = que.front();
                que.pop();
                // 遍历 curr 的所有相邻节点
                for(int i = 0; i < 4; ++i) {
                    int x = curr.first + direction[i][0];
                    int y = curr.second + direction[i][1];
                    // 判断该节点是否有效（不越界）且未访问过（mat[x][y] 小于0）
                    if(x < 0 || y < 0 || x >= row || y >= col || mat[x][y] >= 0) {
                        continue;
                    }
                    mat[x][y] = level;
                    que.push(make_pair(x, y));
                }
            }
            ++level;
        }
        return mat;
    }
private:
    vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};
};

int main() {
    Solution solution;
    vector<vector<int>> mat{{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> ans = solution.updateMatrix(mat);
    return 0;
}