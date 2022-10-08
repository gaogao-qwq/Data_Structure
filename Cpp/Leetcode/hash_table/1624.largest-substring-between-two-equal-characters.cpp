/* https://leetcode.cn/problems/largest-substring-between-two-equal-characters/ */
#include "LC.h"

int maxLengthBetweenEqualCharacters(string s) {
    int ans = -1;
    unordered_map<char, int> umap;
    for(int i = 0; i < s.size(); ++i) {
        if( umap.find(s[i]) != umap.end() ) {
            ans = max(ans, i - umap.find(s[i])->second - 1);
        } else {
            umap.emplace(s[i], i);
        }
    }
    return ans;
}

int main(void) {
    string s = "cabbac";
    cout << maxLengthBetweenEqualCharacters(s);
    return 0;
} 