#include "LC.h"

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        for (int i = 0; i < sequence.size(); ++i) {
            if (sequence[i] == word[0]) {
                int j = 0, cnt = 0, tmp = 0;
                for (; i + j < sequence.size(); ++j) {
                    if (sequence[i + j] == word[j % word.size()]) ++cnt;
                    else break;
                    if (cnt == word.size()) cnt = 0, ++tmp;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.maxRepeating("ababc", "ab");
    return 0;
}