/* https://leetcode.cn/problems/intersection-of-two-arrays-ii/ */
#include "LC.h"

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> umap1, umap2;
        int n = nums1.size(), m = nums2.size();
        for(auto i : nums1) {
            ++umap1[i];
        }
        for(auto i : nums2) {
            ++umap2[i];
        }
        for(auto i = umap1.begin(); i != umap1.end();) {
            if(umap2.find((*i).first) != umap2.end() && umap2[(*i).first] > 0 && (*i).second > 0) {
                --(*i).second;
                --umap2[(*i).first];
                ans.push_back((*i).first);
                continue;
            }
            ++i;
        }
        return ans;
    }


int main() {
    vector<int> nums1{4,9,5}, nums2{9,4,9,8,4};
    auto ans = intersect(nums1, nums2);
    return 0;
}