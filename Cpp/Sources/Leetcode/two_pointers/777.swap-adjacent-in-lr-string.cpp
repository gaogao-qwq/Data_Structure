/* https://leetcode.cn/problems/swap-adjacent-in-lr-string/ */
#include "LC.h"

// 与其说是双指针，不如说是脑筋急转弯
    bool canTransform(string start, string end) {
        int j = 0, n = start.length();
        for(int i = 0; i < n; i++) {
            if(start[i] == 'X') continue;
            for(; j < n; j++) {
                if (end[j] != 'X') break;               
            }
            if(j == n || start[i] != end[j]) return false;
            if(start[i] == 'L' && i < j) return false; // 'L'只能往左走
            if(start[i] == 'R' && i > j) return false; // 'R'只能往右走
            j++;
        }
        for(; j < n; j++) {
            if(end[j] != 'X') return false;
        }
        return true;
    }

int main() {
    cout << boolalpha << canTransform("LXXLXRLXXL", "XLLXRXLXLX");
    return 0;
}