#include <bits/stdc++.h>
using namespace std;

    bool equalFrequency(string word) {
        bool flag = true;
        for(int i = 0; i < word.length(); ++i) {
            flag = true;
            string tmp = word;
            tmp.erase(tmp.begin() + i);
            unordered_map<char, int> umap;
            for(auto i : tmp) {
                ++umap[i];
            }
            int freq = (*umap.begin()).second;
            for(auto i : umap) {
                if(freq != i.second) {
                    flag = false;
                }
            }
            if(flag == true) break;
        }
        return flag;
    }

int main() {
    string word = "aabc";
    cout << boolalpha <<equalFrequency(word);
    return 0;
}