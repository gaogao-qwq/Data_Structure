#include "LC.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (flowerbed.size() == 1) return !n || !flowerbed[0];
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (!i && !flowerbed[i] && !flowerbed[i + 1]) {
                flowerbed[i] = 1, ++cnt;
                continue;
            }
            if (i == flowerbed.size() - 1 && !flowerbed[i] && !flowerbed[i - 1]) {
                flowerbed[i] = 1, ++cnt;
                continue;
            }
            if (!i || i == flowerbed.size()) continue;
            if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
                flowerbed[i] = 1, ++cnt;
            }
        }
        return cnt >= n;
    }
};

int main() {
    Solution s;
    vector<int> flowerbed{1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed, 2);
}