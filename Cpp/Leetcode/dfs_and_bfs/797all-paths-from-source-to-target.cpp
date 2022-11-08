#include "LC.h"

class Solution {
public:
    void dfs(vector<vector<int>> &graph, int index) {
        path.push_back(index);
        for (int i = 0; i < graph[index].size(); ++i) {
            dfs(graph, graph[index][i]);
        }
        if (index == graph.size() - 1) ans.push_back(path);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
private:
    vector<int> path;
    vector<vector<int>> ans;
};

int main() {
    Solution s;
    vector<vector<int>> graph{{4,3,1},{3,2,4},{3},{4},{}};
    for (auto i : s.allPathsSourceTarget(graph)) {
        for (auto j : i) {
            cout << j;
        }
        cout << " ";
    }
    return 0;
}