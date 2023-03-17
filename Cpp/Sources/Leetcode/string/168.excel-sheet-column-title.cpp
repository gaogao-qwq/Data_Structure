#include "LC.h"

// 简单 数学 + 字符串题目，但是要注意这里的 26 进制要减一
class Solution {
public:
    string convertToTitle(int columnNumber) {
        if (columnNumber <= 26) return *new string(1, 'A' + columnNumber - 1);
        string ans;
        while (columnNumber > 0) {
            if (columnNumber % 26 == 0) {
                ans.push_back('Z');
                columnNumber = columnNumber / 26 - 1;
                continue;
            } else {
                ans.push_back('A' + (columnNumber % 26) - 1);
            }
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(52) << endl;
    return 0;
}