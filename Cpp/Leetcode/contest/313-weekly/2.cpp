#include <bits/stdc++.h>
using namespace std;

    int maxSum(vector<vector<int>>& grid) {
        int ans = 0, r = grid.size() - 2, c = grid[0].size() - 2;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                ans = max(ans, grid[i]  [j] + grid[i]  [j+1] + grid[i]  [j+2]
                                            + grid[i+1][j+1]
                             + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]);
            }
        }
        return ans;
    }

int main() {
    vector<vector<int>> grid{{1,2,3},{4,5,6},{7,8,9}};
    cout << maxSum(grid);
    return 0;
}