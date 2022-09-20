/* https://leetcode.cn/problems/sort-array-by-increasing-frequency/ */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    if(nums.size() < 2) return nums;
    unordered_map<int, int> freq;
    vector<int> ans;
    vector<pair<int, int>> tmp;
    for(auto i : nums) {
        if(freq.find(i) == freq.end()) {
            freq.emplace(i, 1);
        } else {
            ++freq[i];
        }
    }
    if(freq.size() == 1) {
        return nums;
    }
    for(auto i : freq) {
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int> a, pair<int ,int> b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    for(int i = 0, j = tmp[0].second; i < tmp.size();) {
        if(j > 0) {
            ans.push_back(tmp[i].first);
            --j;
        } else {
            ++i;
            j = (i < tmp.size())? tmp[i].second : 0;
        }
    }
    return ans;
}

int main() {
    vector<int> nums{-9,-9,-2};
    vector<int> ans = frequencySort(nums);
    return 0;
}