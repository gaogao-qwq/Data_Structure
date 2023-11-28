#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<char> uset = {'a', 'e', 'i', 'o', 'u'};
string s;
char ans = 'a';

int main (int argc, char *argv[]) {
	cin >> s;
	for (const auto &c : s) {
		if (uset.find(c) != uset.end()) ans = c;
	}
	cout << ans;
	return 0;
}
