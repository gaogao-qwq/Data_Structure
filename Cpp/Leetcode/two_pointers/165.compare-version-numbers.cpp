/* https://leetcode.cn/problems/compare-version-numbers/ */
#include "LC.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> s1, s2;
        for(int i = 0, j = 0; i < version1.length(); ++i) {
            if(!i) {
                s1.emplace_back("");
                s1[0].push_back(version1[i]);
                continue;
            }
            if(version1[i] == '.') {
                s1.push_back("");
                ++j;
                continue;
            }
            s1[j].push_back(version1[i]);
        }
        for(int i = 0, j = 0; i < version2.length(); ++i) {
            if(!i) {
                s2.emplace_back("");
                s2[0].push_back(version2[i]);
                continue;
            }
            if(version2[i] == '.') {
                s2.push_back("");
                ++j;
                continue;
            }
            s2[j].push_back(version2[i]);
        }
        int n = (s1.size() > s2.size()) ? s2.size() : s1.size();
        int m = (s1.size() > s2.size()) ? s1.size() : s2.size();
        for(int i = 0; i < n; ++i) {
            if(stoi(s1[i]) < stoi(s2[i])) {
                return -1;
            }
            if(stoi(s1[i]) > stoi(s2[i])) {
                return 1;
            }
        }
        if(s1.size() > s2.size()) {
            for(int i = n; i < m; ++i) {
                if(stoi(s1[i]) != 0) return 1;
            }
            return 0;
        }
        for(int i = n; i < m; ++i) {
            if(stoi(s2[i]) != 0) return -1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.0", "1");
    return 0;
}