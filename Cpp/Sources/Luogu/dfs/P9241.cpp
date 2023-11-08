#include <bits/stdc++.h>
using namespace std;

struct Plane {
    int t, d, l;
};

int T = 0, N = 0;
vector<Plane> planes;
vector<bool> used;

bool dfs(int depth, int currTime) {
    if (depth >= N) return true;
    for (int i = 0; i < N; ++i) {
        if (used[i] || planes[i].t + planes[i].d < currTime) continue;
        used[i] = true;
        if (dfs(depth + 1, max(planes[i].t, currTime) + planes[i].l)) {
            used[i] = false;
            return true;
        }
        used[i] = false;
    }
    return false;
}

int main(int argc, char *argv[]) {
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        planes = std::move(vector<Plane>(N));
        used = std::move(vector<bool>(N));
        for (int j = 0; j < N; ++j) {
            cin >> planes[j].t >> planes[j].d >> planes[j].l;
        }
        cout << (dfs(0, 0) ? "YES" : "NO") << endl;
    }
}