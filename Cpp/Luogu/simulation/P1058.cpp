#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	vector<string> square = {
		"..+---+",
		"./   /|",
		"+---+ |",
		"|   | +",
		"|   |/.",
		"+---+.."
	};
	int m = 0, n = 0;
	cin >> m >> n;
	vector<vector<int>> mat(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	int L = 7 + 4 * (n - 1);
	vector<vector<char>> img()
	return 0;
}
