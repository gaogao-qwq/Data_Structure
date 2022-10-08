/* https://leetcode.cn/problems/valid-sudoku/ */
#include "LC.h"

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9));
        vector<vector<int>> col(9, vector<int>(9));
        vector<vector<int>> box(9, vector<int>(9));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int curr = board[i][j] - '0';
                if(row[i][curr - 1]) return false;
                if(col[j][curr - 1]) return false;
                if(box[j / 3 + (i / 3) * 3][curr - 1]) return false;
                // 若都没出现过，则在对应行、列、宫对应哈希表中设1
                row[i][curr - 1] = 1;
                col[j][curr - 1] = 1;
                box[j / 3 + (i / 3) * 3][curr - 1] = 1;
            }
        }
        return true;
    }

int main() {
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'}
                              ,{'6','.','.','1','9','5','.','.','.'}
                              ,{'.','9','8','.','.','.','.','6','.'}
                              ,{'8','.','.','.','6','.','.','.','3'}
                              ,{'4','.','.','8','.','3','.','.','1'}
                              ,{'7','.','.','.','2','.','.','.','6'}
                              ,{'.','6','.','.','.','.','2','8','.'}
                              ,{'.','.','.','4','1','9','.','.','5'}
                              ,{'.','.','.','.','8','.','.','7','9'}};
    cout << boolalpha << isValidSudoku(board);
    return 0;
}