#include <bits/stdc++.h>
using namespace std;

/**
 * 将结点分成两个集合：已确定最短路长度的点集（记为 S 集合）的和未确定最短路长度的点集（记为 T 集合）。一开始所有的点都属于 T 集合。
 * 
 * 初始化 dis(s)=0，其他点的 dis 均为 +infinity。
 * 
 * 然后重复这些操作：
 * 
 * 从 T 集合中，选取一个最短路长度最小的结点，移到 S 集合中。
 * 对那些刚刚被加入 S 集合的结点的所有出边执行松弛操作。
 * 直到 T 集合为空，算法结束。
 *
 * 优化：优先队列
 */

#define INF 2147483647
#define MAXN 100004

struct edge {
	unsigned int v, w;
};

struct node {
	unsigned int dis, u;

	bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[MAXN];
unsigned int dis[MAXN], vis[MAXN], N, M, S, u, v ,w, i;
priority_queue<node, vector<node>, greater<node>> pq;
int main(void) {
	cin >> N >> M >> S;
	for (i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		e[u].push_back(edge{v, w});
	}
	memset(dis, INF, (N + 1) * sizeof(int));
	dis[S] = 0;
	pq.push(node{0, S});
	while (!pq.empty()) {
		u = pq.top().u;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto ed : e[u]) {
			v = ed.v, w = ed.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(node{dis[v], v});
			}
		}
	}
	for (i = 1; i <= N; ++i) {
		cout << dis[i] << " ";
	}
	return 0;
}
