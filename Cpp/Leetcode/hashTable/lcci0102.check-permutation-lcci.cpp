#include "LC.h"

// 哈希表做法
bool CheckPermutation(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    unordered_map<char, int> umap;
    for(auto i : s1) {
        ++umap[i];
    }
    for(auto i : s2) {
        --umap[i];
    }
    for(auto i : umap) {
        if(i.second != 0) {
            return false;
        }
    }
    return true;
}

// 调库偷鸡做法
bool CheckPermutationSort(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i = 0; i < s1.size(); ++i) {
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

int main () {
    string s1 = "asvnpzurz", s2 = "urzsapzvn";
    cout << boolalpha << CheckPermutation(s1, s2);
    return 0;
}