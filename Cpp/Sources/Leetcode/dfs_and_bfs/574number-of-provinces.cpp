#include "LC.h"

// 朴素做法
class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int i) {
        isConnected[i][i] = 2;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j] == 1) {
                isConnected[i][j] = 2;
                isConnected[j][i] = 2;
                dfs(isConnected, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j && isConnected[i][j] == 1) {
                    isConnected[i][j] = 2;
                    ++cnt;
                    continue;
                }
                if (isConnected[i][j] == 1) {
                    isConnected[i][j] = 2;
                    isConnected[j][i] = 2;
                    dfs(isConnected, j);
                }
            }
        }
        return cnt;
    }
private:
    int cnt = 0;
};

// TODO: 并查集
class Solution2 {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {

    }
};

int main() {
    Solution s;
    vector<vector<int>> isConnected{{1,1,0},{1,1,0},{0,0,1}};
    cout << s.findCircleNum(isConnected) << endl;
    return 0;
}