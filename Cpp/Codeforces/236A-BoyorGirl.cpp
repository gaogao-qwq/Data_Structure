/* https://codeforces.com/problemset/problem/236/A */
#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    int cnt = 0;
    unordered_map<char, int> umap;
    string s = "";
    cin >> s;
    for(auto i : s) {
        if(umap.count(i)) {
            umap[i]++;
        } else {
            umap.emplace(i, 1);
        }
    }
    if(!(umap.size() % 2)) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
    return 0;
}