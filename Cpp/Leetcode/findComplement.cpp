/* https://leetcode.cn/problems/number-complement/ */

#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        string str = bitset<32>(num).flip().to_string();
        int n = str.size();
        for(int i = 0; i < n; ++i) {
            if(!(str[i] - '0')) {
                str = str.substr(i, n - i);
                break;
            }
        }
        return bitset<32>(str).to_ulong();
    }
};

int main(void) {
    Solution solution;
    cout << solution.findComplement(5) << endl;
    return 0;
}