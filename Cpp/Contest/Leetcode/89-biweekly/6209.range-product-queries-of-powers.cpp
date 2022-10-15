/* https://leetcode.cn/problems/range-product-queries-of-powers/ */
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

class Solution {
private:
    const int mod = 1e9+7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers, ans(queries.size());
        while (n) {
            if(n == 1) {
                powers.push_back(1);
                break;
            }
            int tmp = pow(2, int(log2(n)));
            powers.push_back(tmp);
            n -= tmp;
        }
        reverse(powers.begin(), powers.end());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = powers[queries[i][0]];
            for (int j = queries[i][0] + 1; j <= queries[i][1]; ++j) {
                ull a = ans[i], b = powers[j];
                ans[i] = (a * b) % mod;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> queries{{0,1},{2,2},{0,3}};
    for (auto i : s.productQueries(919, queries)) {
        cout << i << " ";
    }
    return 0;
}