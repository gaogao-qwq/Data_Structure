#include <iostream>
#include <string>
#define ll long long
using namespace std;

string s;
ll num = 9223372036854775807LL;

int main (int argc, char *argv[]) {
	cin >> s;
	while (num >= 10) {
		ll tmp = s[0] - '0';
		for (int i = 1; i < (int)s.size(); ++i) {
			ll n = s[i] - '0';
			if (!n) continue;
			tmp *= n;
		}
		s = to_string(tmp);
		cout << tmp << '\n';
		num = tmp;
	}
	return 0;
}
