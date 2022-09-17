/* https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/ */
/* https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/solution/by-tsreaper-qzp3/ */
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int numberOfWays(int startPos, int endPos, int k) {
    int d = abs(endPos - startPos);
    if((d + k) % 2 || d > k) return 0;
    vector<vector<long long>> C;
    C.resize(k + 1, vector<long long>(k + 1));
    for(int i = 0; i <= k; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    return C[k][(d + k) / 2];
}

int main(void) {
    cout << numberOfWays(1, 5, 10) << endl;
    return 0;
}