/* https://leetcode.cn/problems/permutations/ */
#include "LC.h"

// 解题核心：将问题抽象成树，再使用 dfs 来按题目要求遍历树中节点
class Solution {
public:
    void backTracking(vector<int>& nums) {
        // 当到达叶子节点
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;  // 退出递归
        }
        for(int i=0; i<nums.size(); ++i){
            // 由于全排列没有那个元素开头一说，因此没有start参数，但是要注意已经push到path中的就不要重复push了
            // 判断nums[i]是否在vector中用count函数，同map
            if(count(path.begin(), path.end(), nums[i])){ 
                continue;
            }
            // 做选择，将nums[i]放到路径中
            path.push_back(nums[i]);
            // 递归回溯
            backTracking(nums);
            // 撤销选择
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1) return {nums};
        backTracking(nums);
        return ans;
    }
private:
    vector<int> path;
    vector<vector<int>> ans;
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    auto ans = solution.permute(nums);
    return 0;
}