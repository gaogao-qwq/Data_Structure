#include "LC.h"

// TODO: complete it
class Solution {
public:
    void dfs(vector<int> &candidates, int num, int target) {
        sum += num;
        tmp.push_back(num);
        if (sum > target) {
            sum -= num;
            tmp.pop_back();
            return;
        }
        if (sum == target) {
            sum -= num;
            ans.push_back(tmp);
            return;
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for (int i = 0; i < candidates.size(); ++i) {
            dfs(candidates, candidates[i], target);
        }
    }
private:
    int sum = 0;
    vector<int> tmp;
    vector<vector<int>> ans;
};

int main() {
    return 0;
}