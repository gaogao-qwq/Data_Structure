#include "LC.h"

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> sortByAge;
        auto len = scores.size();
        for (int i = 0; i < len; ++i) {
            sortByAge.emplace_back(ages[i], scores[i]);
        }
        sort(sortByAge.begin(), sortByAge.end(), [&](pair<int, int> a, pair<int, int> b) {
            return b.first > a.first || (b.first == a.first && b.second > a.second);
        });

        int ans = 0;
        vector<int> dp(len, 0);
        for (int i = 0; i < len; ++i) {
            dp[i] = sortByAge[i].second;
            for (int j = 0; j < i; ++j) {
                if (sortByAge[i].second >= sortByAge[j].second) {
                    dp[i] = max(dp[i], dp[j] + sortByAge[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> scores{1,3,7,3,2,4,10,7,5}, ages{4,5,2,1,1,2,4,1,4};
    auto ans = s.bestTeamScore(scores, ages);
    cout << ans;
}