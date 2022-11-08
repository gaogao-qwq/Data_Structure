#include "LC.h"

// TODO: complete it!
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
private:
    // 上下左右
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};
};

int main() {
    Solution s;
    vector<vector<char>> board{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(board);
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
         cout << endl;
    }
    return 0;
}