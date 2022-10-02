/* https://leetcode.cn/problems/reformat-phone-number/ */
#include "LC.h"

    string reformatNumber(string number) {
        string ans;
        for(auto i : number) {
            if(i != ' ' && i != '-') {
                ans.push_back(i);
            }
        }
        if(ans.size() < 4) {
            return ans;
        }
        for(int i = 0; i < ans.size();) {
            if(ans.size() - i > 4) {
                i += 3;
                ans.insert(ans.begin() + i, 1, '-');
                ++i;
                continue;
            }
            if(ans.size() - i == 4) {
                i += 2;
                ans.insert(ans.begin() + i, 1, '-');
                ++i;
                continue;
            }
            ++i;
        }
        return ans;
    }

int main() {
    string number = "1-23-45 6";
    cout << reformatNumber(number);
    return 0;
}