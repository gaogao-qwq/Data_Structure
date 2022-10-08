/* https://leetcode.cn/problems/advantage-shuffle/ */
#include "LC.h"

// 超时
class Solution1 {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        multiset<int> n1;
        for(auto i : nums1) {
            n1.emplace(i);
        }
        for(int i = 0; i < nums2.size(); ++i) {
            bool flag = true;
            for(auto j = n1.begin(); j != n1.end(); ++j) {
                if(*j > nums2[i]) {
                    ans.push_back(*j);
                    n1.erase(j);
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(*n1.begin());
                n1.erase(n1.begin());
            }
        }
        return ans;
    }
};

// 使用 multiset 排序，降低 erase 的时间复杂度开销
class Solution2 {
    public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // 取消 cin 与 stdin 的同步
        ios::sync_with_stdio(false);
        multiset<int> mset(A.begin(), A.end());
        vector<int> ans;
        for (auto p : B) {
            auto iter = mset.upper_bound(p);
            if (iter == mset.end()) {
                ans.push_back(*mset.begin());
                mset.erase(mset.begin());
                continue;
            }
            ans.push_back(*iter);
            mset.erase(iter);
        }
        return ans;
    }
};

int main() {
    Solution2 s;
    vector<int> n1{2,7,11,15}, n2{1,10,4,11};
    for(auto i : s.advantageCount(n1, n2)) {
        cout << i << " ";
    }
    return 0;
}
