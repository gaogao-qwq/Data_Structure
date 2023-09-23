#include "LC.h"

class Solution {
public:
    unordered_map<int, vector<int>> map;
    int step;
    int dest;
    int ans = 0;
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        step = k;
        dest = n - 1;
        for (auto &i: relation) {
            map[i[0]].push_back(i[1]);
        }
        for (int j: map[0]) {
            dfs(j);
        }
        return ans;
    }

    void dfs(int num) {
        --step;
        if (!step) {
            if (num == dest) ++ans;
            ++step;
            return;
        }
        if (map[num].empty()) {
            ++step;
            return;
        }
        for (int j: map[num]) {
            dfs(j);
        }
        ++step;
    }
};

int main() {
    Solution s;
    vector<vector<int>> relation = {{0, 2},
                                    {2, 1},
                                    {3, 4},
                                    {2, 3},
                                    {1, 4},
                                    {2, 0},
                                    {0, 4}};
    cout << s.numWays(5, relation, 3);
}