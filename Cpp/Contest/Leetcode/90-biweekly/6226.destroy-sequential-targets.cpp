#include <bits/stdc++.h>
using namespace std;

// 哈希表用对了，但是你数学不及格
class Solution1 {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        if (space == 1) return *min_element(nums.begin(), nums.end());
        int ans = INT32_MAX, maxCnt = 0;
        unordered_map<int, int> umap;
        for (auto i : nums) {
            ++umap[i];
        }
        for (int i = 0; i < n; ++i) {
            int f0 = nums[i], cnt = 0;
            for (auto i : umap) {
                if ((i.first - f0) % space == 0) cnt += i.second;
            }
            if (cnt > maxCnt) {
                maxCnt = cnt;
                ans = nums[i];
            } else if (cnt == maxCnt && nums[i] < ans) {
                ans = nums[i];
            }
        }
        return ans;
    }
};

// 由 nums[j] = nums[i] + c * space
// 可得 nums[j] % space = nums[i] % space
// TODO: debug
class Solution2 {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> umap;
        for (auto i : nums) {
            ++umap[i];
        }
        int _max = max_element(umap.begin(), umap.end(),
                               [] (const pair<int, int> &p1, const pair<int, int> &p2) {
                                    return p1.second < p2.second;
                               })->second;
        int ans = INT32_MAX;
        for (auto i : nums) {
            if (umap.find(i % space) != umap.end() && umap[i % space] == _max && i < ans) {
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    vector<int> nums{1,5,3,2,2};
    cout << s1.destroyTargets(nums, 10000) << endl;
    cout << s2.destroyTargets(nums, 10000) << endl;
    return 0;
}