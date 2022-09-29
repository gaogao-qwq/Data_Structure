#include "LC.h"

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> nums{3, 5, 7};
        unordered_set<long> visited;
        priority_queue<long, vector<long>, greater<long>> que;
        visited.insert(1L);
        que.push(1L);
        int ans = 0;
        for(int i = 0; i < k; ++i) {
            long curr = que.top();
            ans = (int)curr;
            que.pop();
            for(auto num : nums) {
                long next = curr * num;
                if(!visited.count(next)) {
                    visited.insert(next);
                    que.push(next);
                }
            }
        }
        return ans;
    }
};

int main () {
    Solution solution;
    cout << solution.getKthMagicNumber(5);
    return 0;
}