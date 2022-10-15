#include <bits/stdc++.h>
using namespace std;

    int transportationHub(vector<vector<int>>& path) {
        unordered_map<int,int> cnt, end, start;
        int n = path.size();
        for(auto i : path) {
            if(cnt.find(i[0]) == cnt.end()) {
                cnt.emplace(i[0], 1);
            }
            if(cnt.find(i[1]) == cnt.end()) {
                cnt.emplace(i[1], 1);
            }
            if(start.find(i[0]) == start.end()) {
                start.emplace(i[0], 1);
            }
            if(end.find(i[1]) == end.end()) {
                end.emplace(i[1], 1);
            } else {
                ++end[i[1]];
            }
        }
        for(auto i : end) {
            if(i.second == cnt.size() - 1 && start.find(i.first) == start.end()) {
                return i.first;
            }
        }
        return -1;
    }

    int main() {
        vector<vector<int>> path{{0,3},{1,0},{1,3},{2,0},{3,0},{3,2}};
        cout << transportationHub(path);
        return 0;
    }