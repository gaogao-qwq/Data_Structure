#include <bits/stdc++.h>
using namespace std;

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0,cnt = 0;
        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0; j < nums2.size(); ++j) {
                if(i == 0 && j == 0) {
                    ans = nums1[i] ^ nums2[j];
                    ++cnt;
                    continue;
                }
                ++cnt;
                ans ^= (nums1[i] ^ nums2[j]);
            }
        }
        return ans;
    }

int main() {
    vector<int> nums1{1,2}, nums2{3,4};
    cout << xorAllNums(nums1, nums2);
    return 0;
}
