/* https://leetcode.cn/problems/next-greater-element-i/ */
#include "LC.h"

// 简单单调栈

// 朴素哈希表O(nlogn)
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); ++i) {
            umap[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); ++i) {
            int tmp = -1, index = umap[nums1[i]];
            for (int j = index + 1; j < nums2.size(); ++j) {
                if (nums2[j] > nums2[index]) {
                    tmp = nums2[j];
                    break;
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

// 哈希表 + 单调栈 平均O(n)
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> ans;
        stack<int> stk;
        for (int i = 0; i < nums2.size(); ++i) {
            if (stk.empty()) {
                stk.push(nums2[i]);
                continue;
            }
            if (nums2[i] > stk.top()) {
                while (!stk.empty() && nums2[i] > stk.top()) {
                    umap[stk.top()] = nums2[i];
                    stk.pop();
                }
                stk.push(nums2[i]);
                continue;
            }
            stk.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (umap.find(nums1[i]) != umap.end()) ans.push_back(umap[nums1[i]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};


int main() {
    Solution1 s1;
    Solution2 s2;
    vector<int> nums1{1,3,5,2,4}, nums2{6,5,4,3,2,1,7};
    for (auto i : s2.nextGreaterElement(nums1, nums2)) {
        cout << i << " ";
    }
    return 0;
}