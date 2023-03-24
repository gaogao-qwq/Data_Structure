#include "LC.h"

class Solution {
public:
    string add(string s) {
        for (int i = 1; i < s.size(); ++i) {
            s[i] = s[i] - '0' + a > 9 ? s[i] + a - 10 : s[i] + a;
        }
        return s;
    }

    string roll(string s) {
        string tmp = s;
        for (int i = 0; i < s.size(); ++i) {
            s[i] = tmp[i - b >= 0 ? i - b : s.size() - b - i];
        }
        return s;
    }

    void bfs(string root) {
        que.push(root);
        while (!que.empty()) {
            string l = add(que.front()), r = roll(que.front());
            que.pop();
            if (uset.insert(l).second) {
                que.push(l);
                min = min <= l ? min : l;
            }
            if (uset.insert(r).second) {
                que.push(r);
                min = min <= r ? min : r;
            }
        }
    }

    string findLexSmallestString(string s, int a, int b) {
        this->a = a, this->b = b, this->min = s;
        bfs(s);
        return min;
    }
private:
    int a = 0;
    int b = 0;
    string min = "";
    queue<string> que;
    unordered_set<string> uset;
};

int main() {
	Solution s;
	cout << s.findLexSmallestString("5525", 9, 2);
}

