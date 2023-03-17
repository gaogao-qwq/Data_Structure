#include "LC.h"

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<char> hash(26);
        int cnt = 0;
        for (auto i : allowed) {
            ++hash[i - 'a'];
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (!hash[words[i][j] - 'a']) break;
                if (j == words[i].size() - 1) ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<string> words{"ad","bd","aaab","baa","badab"};
    cout << s.countConsistentStrings("ab", words) << endl;
    return 0;
}