#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> img(550, vector<char>(550));
const vector<string> square = {
	"..+---+",
	"./   /|",
	"+---+ |",
	"|   | +",
	"|   |/.",
	"+---+.."
};

inline void draw(int x, int y) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 7; ++j) {
			if (square[6 - i - 1][j] != '.')
				img[x - i][y + j] = square[6 - i - 1][j];
		}
	}
}

int main(int argc, char *argv[]) {
	int m = 0, n = 0;
	cin >> m >> n;
	int L = 4 * n + 2 * m + 1, K = 0;
	vector<vector<int>> mat(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> mat[i][j];
			K = max(K, mat[i][j] * 3 + 2 * (m - i + 1) + 1);
		}
	}
	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= L; ++j) {
			img[i][j] = '.';
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x = K - 2 * (m - i), y = 2 * (m - i) + 4 * (j - 1) + 1;
			while (mat[i][j]--) {
				draw(x, y);
				x -= 3;
			}
		}
	}
	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j <= L; ++j) {
			cout << img[i][j];
		}
		cout << endl;
	}
	return 0;
}
