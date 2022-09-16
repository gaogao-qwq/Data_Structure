#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans{{1}, {1, 1}};
    if (numRows == 1) return vector<vector<int>>{{1}};
    ans.resize(numRows);
    for (int i = 2; i < numRows; ++i) {
        ans[i].resize(i + 1);
        for (int j = 0; j < i + 1; ++j) {
            if(!j || j == i) {
                ans[i][j] = 1;
                continue;
            }
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}

int main(void) {
    vector<vector<int>> ans = generate(5);
    return 0;
}