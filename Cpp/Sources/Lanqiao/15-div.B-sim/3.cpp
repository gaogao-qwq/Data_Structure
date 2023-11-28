#include <cmath>
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	int cnt = 1;
	for (int i = 1; cnt <= 32; ++i) {
		int t2 = i, sum2 = 0, t8 = i, sum8 = 0;
		while (t2 >= 2) {
			sum2 += t2 % 2;
			t2 /= 2;
		}
		sum2 += t2;
		while (t8 >= 8) {
			sum8 += t8 % 8;
			t8 /= 8;
		}
		sum8 += t8;
		if (sum2 == sum8) {
			++cnt;
			cout << i << ' ';
		}
	}
	return 0;
}
