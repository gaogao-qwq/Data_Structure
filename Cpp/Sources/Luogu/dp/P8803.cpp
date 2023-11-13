#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

struct Bill {
	int d, v;
};

const int days[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int N = 0, M = 0, K = 0;
array<Bill, 1002> bills;
array<int, 1002> lll; // last legal location
array<array<int, 5002>, 1002> dp;
int curr = 0, last = -60;

int main (int argc, char *argv[]) {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
		int	m = 0, d = 0, v = 0;
		cin >> m >> d >> v;
		bills[i].d = days[m] + d, bills[i].v = v;
    }
	sort(bills.begin() + 1, bills.begin() + 1 + N, [](auto &a, auto &b) { return a.d < b.d; });
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j >= 0; --j) {
			if (bills[i].d - bills[j].d >= K) {
				lll[i] = j; break;
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = M; j >= bills[i].v; --j) {
			dp[i][j] = max(dp[i - 1][j], dp[lll[i]][j - bills[i].v] + bills[i].v);
		}
	}
	cout << dp[N][M];
}

