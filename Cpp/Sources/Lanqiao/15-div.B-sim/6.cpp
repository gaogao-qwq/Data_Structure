#include <iostream>
#include <string>
using namespace std;

string s;

int main (int argc, char *argv[]) {
	cin >> s;
	s = s.substr(1, 5) + s[0];
	cout << stoi(s);
	return 0;
}
