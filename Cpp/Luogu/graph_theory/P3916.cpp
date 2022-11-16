#include <bits/stdc++.h>
using namespace std;

int tmp = 0;
vector<int> ans;
unordered_set<int> uset;

void dfs(vector<vector<int>>adj, int p) {
    for (int i = 0; i < adj.size(); ++i) {
        if (adj[i][0] == p) {
            dfs(adj, adj[i][1]);
        }
    }
}

int main() {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<vector<int>> adj(M, vector<int>(2));
    // 反向建边
    for (int i = 0; i < M; ++i)
        cin >> adj[i][1] >> adj[i][0];
    // 从 N 遍历到 1
    for (int i = N; i >= 1; --i)
        dfs(adj, i);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}