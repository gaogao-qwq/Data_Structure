#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> points, dis;
vector<bool> vis;
int N = 0, M = 0, ans = 0;

void dijkstra() {
    dis.resize(N + 1, INT_MAX);
    vis.resize(N + 1, false);
    int min_i = 1;
    dis[min_i] = 0, vis[min_i] = true;
    while (!vis[N]) {
        for (auto i : graph[min_i]) {
            if (vis[i.first]) continue;
            dis[i.first] = min(dis[i.first], dis[min_i] + i.second);
        }
        int min_d = INT_MAX;
        for (int i = 1; i <= N; ++i) {
            if (vis[i]) continue;
            if (dis[i] < min_d) min_d = dis[i], min_i = i;
        }
        vis[min_i] = true;
//        for (int i = 1; i <= N; ++i) {
//            cout << i << " " << dis[i] << " " << boolalpha << vis[i] << endl;
//        }
//        cout << "min_i = " << min_i << endl;
    }
    ans = dis[N] - points[N];
}

int main (int argc, char *argv[]) {
    cin >> N >> M;
    points.resize(N + 1);
    graph.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> points[i];
    }
    for (int i = 1; i <= M ; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].emplace_back(v, c+points[v]);
        graph[v].emplace_back(u, c+points[u]);
    }
    dijkstra();
    cout << ans;
}