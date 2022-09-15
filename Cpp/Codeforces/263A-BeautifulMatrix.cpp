/* https://codeforces.com/problemset/problem/263/A */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<vector<int>> mat(5, vector<int> (5, 0));
    int row = 0, col = 0;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> mat[i][j];
            if(mat[i][j] == 1) {
                row = i, col = j;
            }
        }
    }
    cout << abs(row - 2) + abs(col - 2);
    return 0;
}