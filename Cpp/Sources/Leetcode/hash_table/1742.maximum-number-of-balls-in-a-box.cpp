#include "LC.h"

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[46] = {0};
        for (int i = lowLimit; i <= highLimit; ++i) {
            int sum = 0, num = i;
            while (num > 0) sum += num % 10, num /= 10;
            // string s = to_string(i);
            // for (auto i : s) {
            //     sum += i - '0';
            // }
            ++cnt[sum];
        }
        int ans = 0;
        for (int i = 0; i < 46; ++i) {
            ans = max(cnt[i], ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countBalls(1, 10);
    return 0;
}