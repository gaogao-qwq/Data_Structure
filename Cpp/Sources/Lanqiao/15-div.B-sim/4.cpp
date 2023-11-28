#include <iostream>
using namespace std;

int cal(int v) {
	int cnt = 0;
	for (int i = 1; i < v; ++i) {
		if (v % i) continue;
		++cnt;
	}
	return cnt;
}

int main (int argc, char *argv[]) {
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= 6; ++j) {
			int n = 0;
			cin >> n;
			cout << cal(n) << '\t';
		}
		cout << '\n';
	}
	return 0;
}

