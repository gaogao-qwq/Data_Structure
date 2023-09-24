#include "LC.h"

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        string s = to_string(num);
        if (s[0] == '-') {
            std::sort(s.begin() + 1, s.end(), [](const char &a, const char &b) {
                return a > b;
            });
            return stoll(s);
        }
        std::sort(s.begin(), s.end());
        if (s[0] == '0') {
            char min_char = 'a';
            int min_index = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != '0' && s[i] < min_char) {
                    min_char = s[i], min_index = i;
                }
            }
            swap(s[0], s[min_index]);
        }
        return stoll(s);
    }
};

int main() {
    Solution s;
    cout << s.smallestNumber(310) << endl;
    cout << s.smallestNumber(-7605) << endl;
}