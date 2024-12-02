#include <bits/stdc++.h>
using namespace std;

int N, i, j, ans, a[2004], b[2004], f[2004][2004], g[2004][2004];
int main (void) {
	cin >> N;
	for (i = 0; i < N; ++i) cin >> a[i];
	for (i = 0; i < N; ++i) cin >> b[i];
	sort(a, a+N, greater<int>()), sort(b, b+N, greater<int>());
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (a[i] > b[j]) g[i][j] = 200;
			else if (a[i] == b[j]) g[i][j] = 0;
			else g[i][j] = -200;
			f[i][j] = INT_MIN;
		}
	}
	for (i = 0; i < N; ++i) {
		f[i][0] = f[i-1][0] + g[N-i+1][i];
		f[i][i] = f[i-1][i-1] + g[i][i];
		for (j = 0; j < i; ++j) f[i][j] = max(f[i-1][j] + g[N-i+j][i], f[i-1][j-1] + g[j][i]);
	}
	for (i = 1; i < N; ++i) ans = max(ans, f[N-1][i]);
	cout << ans << "\n";
	return 0;
}
