#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		stack<string> stk;
		int n = 0;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			string op;
			cin >> op;
			if (op[0] == 'p' && op[1] == 'u') {
				string param;
				cin >> param;
				stk.push(param);
				continue;
			}
			if (op[0] == 'q') {
				if (stk.empty()) {
					cout << "Anguei!" << endl;
					continue;
				}
				cout << stk.top() << endl;
				continue;
			}
			if (op[0] == 's') {
				cout << stk.size() << endl;
				continue;
			}
			if (op[0] == 'p' && op[1] == 'o') {
				if (stk.empty()) {
					cout << "Empty" << endl;
					continue;
				}
				stk.pop();
			}
		}
	}
}
