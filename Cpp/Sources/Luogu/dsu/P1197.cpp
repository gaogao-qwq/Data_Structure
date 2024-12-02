#include <bits/stdc++.h>
using namespace std;
#define MAXLEN 400004

int N, M, K, i, j, u, v, cnt, p[MAXLEN];
bool vis[MAXLEN];
vector<vector<int>> e;

void init() {
	for (i = 0; i < N; ++i)
		p[i] = i;
}

int find(int u) {
	if (p[u] == u) return u;
	p[u] = find(p[u]);
	return p[u];
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u != v)
		p[u] = v;
}

int main (int argc, char *argv[]) {
	cin >> N >> M;
	e.resize(N);
	init();
	for (i = 0; i < M; ++i) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		merge(u, v);
	}
	for (i = 0; i < N; ++i)
		if (i == find(i)) ++cnt;
	cout << cnt << "\n";
	cin >> K;
	while(K--) {
		cin >> u;
		init();
		cnt = 0, vis[u] = true;
		for (i = 0; i < N; ++i) {
			if (vis[i]) continue;
			for (j = 0; j < e[i].size(); ++j) {
				if (vis[e[i][j]]) continue;
				merge(i, e[i][j]);
			}
		}
		for (i = 0; i < N; ++i)
			if (i == find(i) && !vis[i]) ++cnt;
		cout << cnt << "\n";
	}
	return 0;
}
