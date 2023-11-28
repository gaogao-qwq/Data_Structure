#include <array>
#include <iostream>
#define ll long long
using namespace std;

int N = 0, K = 0, sum = 0, ans = 0;
array<ll, 100005> arr;
// vector<vector<ll>> psum;

int main (int argc, char *argv[]) {
	cin >> N >> K;
	// psum = std::move(vector<vector<ll>>(N + 5, vector<ll>(N + 5)));
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	// for (int i = 1; i <= N; ++i) psum[i][i] = arr[i];
	// for (int r = 1; r <= N; ++r) {
	// 	for (int c = r + 1; c <= N; ++c) {
	// 		psum[r][c] = psum[r][c - 1] + arr[c];
	// 	}
	// }
	// for (int l = 1, r = l + K - 1; r <= N; ++l, ++r) {
	// 	ans = psum[l][r] > ans ? psum[l][r] : ans;
	// }
	for (int i = 1; i < K + 1; ++i) {
		sum += arr[i];
	}
	for (int l = 2, r = l + K - 1; r <= N; ++l, ++r) {
		sum -= arr[l - 1], sum += arr[r];
		ans = sum > ans ? sum : ans;
	}
	cout << ans;
	return 0;
}
