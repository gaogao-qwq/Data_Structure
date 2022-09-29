/* https://leetcode.cn/problems/find-resultant-array-after-removing-anagrams/ */
#include "LC.h"

    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size() == 1) {
            return words;
        }
        vector<string> tmp = words;
        int n = tmp.size();
        for(auto i = tmp.begin(); i != tmp.end(); ++i) {
            sort((*i).begin(), (*i).end());
        }
        for(int i = 1; i < n; ++i) {
            if(tmp[i] == tmp[i - 1]) {
                words.erase(words.begin() + i);
                tmp.erase(tmp.begin() + i);
                --i, --n;
            }
        }
        return words;
    }

int main() {
    vector<string> words{"abba","baba","bbaa","cd","cd"};
    for(auto i : removeAnagrams(words)) {
        cout << i << " ";
    }
    return 0;
}