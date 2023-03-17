/* https://leetcode.cn/problems/goal-parser-interpretation/ */
#include "LC.h"

class Solution {
public:
    string interpret(string command) {
        string tmp, ans;
        unordered_map<string, string> umap{{"G", "G"}, {"()", "o"}, {"(al)", "al"}};
        for (int i = 0; i < command.length(); ++i) {
            tmp.push_back(command[i]);
            if (umap.find(tmp) != umap.end()) ans += umap[tmp], tmp = "";
        }
        return ans;
    } 
};

int main() {
    Solution s;
    cout << s.interpret("G()()()()(al)") << endl;
    return 0;
}