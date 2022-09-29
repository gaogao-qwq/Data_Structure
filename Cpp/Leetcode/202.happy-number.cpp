/* https://leetcode.cn/problems/happy-number/ */
#include "LC.h"

int squareSum(int n) {
    int ret = 0;
    while(n > 0) {
        ret += pow(n % 10, 2);
        n /= 10;
    }
    return ret;
}
bool isHappy(int n) {
    int count = 0;
    while(count < 20) {
        n = squareSum(n);
        if(n == 1) return true;
        ++count;
    }
    return false;
}

int main(void) {
    cout << boolalpha << isHappy(19);
    return 0;
}
