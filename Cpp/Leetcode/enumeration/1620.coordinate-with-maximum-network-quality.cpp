#include "LC.h"

// 看数据量和题目要求得知仅需要考虑坐标轴上第一象限且 x,y <= 100
// 无法通过第98个测试用例，神秘
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ans(2);
        // 造一个数组用来存储第一象限每一整数格的信号强度
        vector<vector<int>> grid(101, vector<int>(101));

        for (int i = 0; i < towers.size(); ++i) {
            int r = towers[i][0], c = towers[i][1], q = towers[i][2];

            // 特殊处理上下左右四个点 grid[r][c] = q / (1 + d)
            grid[r + radius][c] += (int)floor(q / (double)(1 + radius));
            if(r - radius >= 0) grid[r - radius][c] += (int)floor(q / (double)(1 + radius));
            grid[r][c + radius] += (int)floor(q / (double)(1 + radius));
            if (c - radius >= 0) grid[r][c - radius] += (int)floor(q / (double)(1 + radius));

            // 暴力枚举
            for (int j = r - radius + 1; j < r + radius; ++j) {
                for (int k = c - radius + 1; k < c + radius; ++k) {
                    if (j < 0 || k < 0) {
                        continue;
                    }
                    // 实际上并不是所有的圆都能包含坐标 (i, j) (i = j = radius - 1) 的，所以只需要加一行判断即可
                    if (pow(j - r, 2) + pow(k - c, 2) > pow(radius, 2)) {
                        continue;
                    }
                    grid[j][k] += (int)floor((double)q / (1 + sqrt(pow(j - r, 2) + pow(k - c, 2))));
                }
            }
        }
        // for (int i = 0; i < grid.size(); ++i) {
        //     for (int j = 0; j < grid[0].size(); ++j) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int _max = 0;
        for (int i = 0 ; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] > _max) {
                    _max = grid[i][j];
                    ans[0] = i, ans[1] = j;
                }
            }
        } 
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> towers{{28,6,30},{23,16,0},{21,42,22},{50,33,34},{14,7,50},{40,31,4},{39,45,17},{46,21,12},{45,36,45},{35,43,43},{29,41,48},{22,27,5},{42,44,45},{10,49,50},{47,43,26},{40,36,25},{10,25,6},{27,30,30},{50,35,20},{11,0,44},{34,29,28}};
    for (auto i : s.bestCoordinate(towers, 12)) {
        cout << i << " ";
    }
    return 0;
}