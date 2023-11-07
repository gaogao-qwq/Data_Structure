#include <bits/stdc++.h>
using namespace std;

int N = 0, M = 0, T = 0;
vector<vector<int>> dis;

void floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dis[i][j] = min(dis[i][j], max(dis[k][j], dis[i][k]));
            }
        }
    }
}

int main(int argc, char *argv[]) {
    cin >> N >> M >> T;
    dis = std::move(vector<vector<int>>(N + 1, vector<int>(N + 1, INT_MAX)));
    for (int i = 1, j = 1; i <= N; ++i, ++j) dis[i][j] = 0;
    for (int i = 0; i < M; ++i) {
        int s = 0, e = 0, h = 0;
        cin >> s >> e >> h;
        dis[s][e] = h;
    }
    floyd();
    for (int i = 0; i < T; ++i) {
        int a = 0, b =0;
        cin >> a >> b;
        cout << (dis[a][b] == INT_MAX ? -1 : dis[a][b]) << endl;
    }
}