#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int _min = INT32_MAX;
            for (int j = 0; j < dictionary.size(); ++j) {
                int cnt = 0;
                for (int k = 0; k < queries[0].length(); ++k) {
                    if (queries[i][k] != dictionary[j][k]) ++cnt;
                }
                _min = min(cnt, _min);
            }
            if (_min <= 2) ans.push_back(queries[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> queries{"word","note","ants","wood"}, dictionary{"wood","joke","moat"};
    for (auto i : s.twoEditWords(queries, dictionary)) cout << i << " ";
    return 0;
}