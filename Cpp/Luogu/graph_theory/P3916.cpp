#include <bits/stdc++.h>
using namespace std;

int tmp = 0;
vector<int> adj[100010];
vector<int> ans;
int h[100010] = {0};

void dfs(int p, int _max) {
    if (h[p]) return;
    ans[p] = _max;
    ++h[p];
    for (int i = 0; i < adj[p].size(); ++i) {
        dfs(adj[p][i], _max);
    }
}

int main() {
    int N = 0, M = 0;
    scanf("%d%d", &N, &M);
    ans.resize(N + 1);
    // 反向建边
    int u = 0, v = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &u, &v);
        adj[v].push_back(u);
    }
    for (int i = N; i >= 1; --i) dfs(i, i);
    for (int i = 1; i <= N; ++i)
        printf("%d ", ans[i]);
    return 0;
}