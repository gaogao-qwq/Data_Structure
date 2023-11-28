#include <array>
#include <iostream>
using namespace std;

int N = 0, M = 0, R = 0, C = 0, ans = 0;
array<array<int, 1005>, 1005> mat;
array<array<bool, 1005>, 1005> vis;

int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

void dfs(int r, int c, int from) {
	if (gcd(mat[r][c], from) == 1 && from != 0) return;
	vis[r][c] = true, ++ans;
	// for (int i = 1; i <= N; ++i) {
	// 	for (int j = 1; j <= M; ++j) {
	// 		cout << vis[i][j] << '\t';
	// 	}
	// 	cout << '\n';
	// }
	// cout << '\n';
	if (r - 1 > 0 && !vis[r - 1][c]) {
		dfs(r - 1, c, mat[r][c]);
	}
	if (r + 1 <= N && !vis[r + 1][c]) {
		dfs(r + 1, c, mat[r][c]);
	}
	if (c - 1 > 0 && !vis[r][c - 1]) {
		dfs(r, c - 1, mat[r][c]);
	}
	if (c + 1 <= M && !vis[r][c + 1]) {
		dfs(r, c + 1, mat[r][c]);
	}
}

int main (int argc, char *argv[]) {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> mat[i][j];
		}
	}
	cin >> R >> C;
	dfs(R, C, 0);
	cout << ans;
	return 0;
}
