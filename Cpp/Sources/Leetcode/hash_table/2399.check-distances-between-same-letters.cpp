/* https://leetcode.cn/problems/check-distances-between-same-letters/ */
#include "LC.h"

bool checkDistances(string s, vector<int>& distance) {
    unordered_map<char, int> umap;
    for(int i = 0; i < s.size(); ++i) {
        if(umap.find(s[i]) == umap.end()) {
            umap.emplace(s[i], i);
            continue;
        }
        if(!(i - umap.find(s[i])->second - 1 == distance[s[i] - 'a'])) {
            return false;
        }
    }
    return true;
}

int main(void) {
    vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string s = "abaccb";
    cout << checkDistances(s, distance);
    return 0;
}