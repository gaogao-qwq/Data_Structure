/* https://leetcode.cn/problems/number-of-valid-clock-times/ */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTime(string time) {
        int a = 1, b = 1;
        if (time[0] == '?' && time[1] == '?') {
            a = 24;
        } else if (time[0] == '?') {
            a = time[1] > '3' ? 2 : 3;
        } else if (time[1] == '?') {
            a = time[0] == '2' ? 4 : 10;
        }
        if (time[3] == '?' && time[4] == '?') {
            b = 60;
        } else if (time[3] == '?') {
            b = 6;
        } else if (time[4] == '?') {
            b = 10;
        }
        return a * b;
    }
};

int main() {
    Solution s;
    string time = "21:??";
    cout << s.countTime(time);
    return 0;
}