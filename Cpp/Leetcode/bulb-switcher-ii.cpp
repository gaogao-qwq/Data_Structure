/* https://leetcode.cn/problems/bulb-switcher-ii/ */
#include <iostream>
using namespace std;

int main(void) {
    int n = 0, presses = 0;
    cin >> n >> presses;
    if (presses > 2 && n > 2) return 8;
    if (n < 3) return 1 + (presses > 0) * n + (presses > 1 && n > 1);
    else return 1 + 3 * presses;
    return 0;
}