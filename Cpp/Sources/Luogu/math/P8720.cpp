#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int N = 0, ans = 1;
vector<pair<double, double>> lines;
set<pair<int, int>> vis;

int main (int argc, char *argv[]) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int k = 0, b = 0;
		cin >> k >> b;
		auto p = make_pair(k, b);
		vis.insert(p);
	}
	for (const auto &i : vis) lines.emplace_back(i.first, i.second);
	for (int i = 0; i < lines.size(); ++i) {
		set<pair<double, double>> points;
		for (int j = 0; j < i; ++j) {
			double k1 = lines[i].first, b1 = lines[i].second,
				   k2 = lines[j].first, b2 = lines[j].second;
			if (k1 == k2) continue;
			double x = (b2 - b1) / (k1 - k2);
			double y = k1 * x + b1;
			points.insert(make_pair(x, y));
		}
		ans += points.size() + 1;
	}
	cout << ans;
}
