#include "LC.h"

class Solution {
public:
    int secondHighest(string s) {
        string s1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9' && s1.find(s[i]) == string::npos)
                s1.push_back(s[i]);
        }
        sort(s1.begin(), s1.end());
        return s1.length() >= 2 ? s1[s1.length() - 2] - '0' : -1;
    }
};

int main() {
    Solution s;
    cout << s.secondHighest("dfa12321afd");
    return 0;
}