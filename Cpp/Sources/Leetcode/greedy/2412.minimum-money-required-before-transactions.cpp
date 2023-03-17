/* https://leetcode.cn/problems/minimum-money-required-before-transactions */
#include "LC.h"

long long minimumMoney(vector<vector<int>>& transactions) {
    sort(transactions.begin(), transactions.end(), [](vector<int> a, vector<int> b) {
        if(a[1] == b[1]) {
            return a[0] < b[0];
        }
        return (a[1] > b[1]);
    });
    long long ans = (transactions.back())[0];
    for(auto i = transactions.rbegin() + 1; i != transactions.rend(); ++i) {
        ans = max(ans + (*i)[0] - (*(i - 1))[1], ans);
    }
    return ans;
}

int main() {
    vector<vector<int>> transactions{{3,9},{0,4},{7,10},{3,5},{0,9},{9,3},{7,4},{0,0},{3,3},{8,0}};
    cout << minimumMoney(transactions);
    return 0;
}