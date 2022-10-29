#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        vector<int> tmp(words[0].size() - 1);
        for (int i = 1; i < words[0].size(); ++i) {
            tmp[i - 1] = words[0][i] - words[0][i - 1];
        }
        for (int i = 1; i < words[0].size(); ++i) {
            if (words[0][i] - words[0][i - 1] != words[1][i] - words[1][i - 1] && words[0][i] - words[0][i - 1] != words[2][i] - words[2][i - 1]) return words[0];
        }
        for (int j = 1; j < words[0].size(); ++j) {
            for (int i = 0; i < n; ++i) {
                if (words[i][j] - words[i][j - 1] != tmp[j - 1]) {
                    return words[i];
                }
            }
        }
        return "";
    }
};

int main() {
    vector<string> words{"klklklkklk","opopopoopo","ijijijiiji","vwvwvwvvwv","vwvwvwvvwv","hihihihhih","opopopoopo","uvuvuvuuvu","ghghghgghg","fgfgfgffgf","tutututtut","cdcdcdccdc","rsrsrsrrsr","qrqrqrqqrq","xyxyxyxxyx","ijijijiiji","mnmnmnmmnm","yzyzyzyyzy","klklklkklk","bcbcbcbbcb","rsrsrsrrsr","abababaaba","wxwxwxwwxw","vwvwvwvvwv","hihihihhih","stststssts","ijijijiiji","uvuvuvuuvu","ijijijiiji","dedededded","pqpqpqppqp","wxwxwxwwxw","hihihihhih","efefefeefe","lmlmlmllml","abababaaba","pqpqpqppqp","xyxyxyxxyx","cdcdcdccdc","qrqrqrqqrq","abbbabbbba","stststssts","fgfgfgffgf","tutututtut","wxwxwxwwxw","qrqrqrqqrq","fgfgfgffgf","cdcdcdccdc","nonononnon","vwvwvwvvwv"};
    Solution s;
    cout << s.oddString(words);
    return 0;
}