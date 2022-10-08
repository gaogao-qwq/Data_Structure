/* https://leetcode.cn/problems/check-array-formation-through-concatenation/ */
#include "LC.h"

bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    int cnt = 0;
    unordered_map<int, int> umap;
    for(int i = 0; i < arr.size(); ++i) {
        umap.emplace(arr[i], i);
    }
    for(int i = 0; i < pieces.size(); ++i) {
        ++cnt;
        if(pieces[i].size() == 1) {
            if(umap.find(pieces[i][0]) == umap.end()) {
                return false;
            }
            continue;
        }
        for(int j = 1; j < pieces[i].size(); ++j) {
            ++cnt;
            if(umap.find(pieces[i][j]) == umap.end() || umap.find(pieces[i][j - 1]) == umap.end()) {
                return false;
            }
            if(umap.find(pieces[i][j])->second != umap.find(pieces[i][j - 1])->second + 1) {
                return false;
            }
        }
    }
    if(cnt != arr.size()) return false;
    return true;
}

int main() {
    vector<int> arr{12};
    vector<vector<int>> pieces{{1}};
    cout << boolalpha << canFormArray(arr, pieces);
    return 0;
}