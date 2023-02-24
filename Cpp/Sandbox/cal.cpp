
#include <bits/stdc++.h>
#include <cstdint>
#include <random>
#include <unordered_set>
using namespace std;
int main() {
	minstd_rand minstd_random_engine;
	mersenne_twister_engine<uint_fast32_t, 32, 624, 397, 31,
							0x9908b0df, 11,
							0xffffffff, 7,
							0x9d2c5600, 15,
							0xefc60000, 18, 1812433253> mersenne_twister_engine;
	int n = 64, try_cnt = 10000000, same_cnt = 0;
	uniform_int_distribution<uint_fast32_t> uniform_int_dist(1, 365);
	for (int i = 0; i < try_cnt; ++i) {
		unordered_set<uint_fast32_t> uset;
		for (int j = 0; j < n; ++j) {
			int tmp = uniform_int_dist(mersenne_twister_engine);
			if (uset.find(tmp) != uset.end()) {
				same_cnt++;
				break;
			}
			uset.insert(tmp);
		}
	}
	cout << "50人的生日在 " << try_cnt << "次尝试中有 " << same_cnt << "次出现了相同生日。" << endl;
}
