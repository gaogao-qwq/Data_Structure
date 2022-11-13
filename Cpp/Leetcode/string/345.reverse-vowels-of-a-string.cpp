/* https://leetcode.cn/problems/reverse-vowels-of-a-string/ */
#include "LC.h"

// 记录元音下标并反转
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> uset{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> index;
        string val;
        for (int i = 0; i < s.length(); ++i) {
            if (uset.find(s[i]) != uset.end()) {
                index.push_back(i);
                val.push_back(s[i]);
            }
        }
        reverse(index.begin(), index.end());
        for (int i = 0; i < index.size(); ++i) {
            s[index[i]] = val[i];
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("hello");
    return 0;
}