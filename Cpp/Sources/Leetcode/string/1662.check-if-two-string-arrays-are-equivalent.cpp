#include "LC.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        int n = word1.size() > word2.size() ? word1.size() : word2.size();
        for (int i = 0; i < n ; ++i) {
            if (i < word1.size()) {
                s1 += word1[i];
            }
            if (i < word2.size()) {
                s2 += word2[i];
            }
        }
        return s1 == s2 ? true : false;
    }
};

int main() {
    Solution s;
    vector<string> word1{"abc","d","ef"}, word2{"abcdef"};
    cout << boolalpha <<s.arrayStringsAreEqual(word1, word2);
    return 0;
}