#include <bits/stdc++.h>
using namespace std;

int N = 0, cnt = 0;
vector<vector<int>> ans{};
vector<int> tmp{};
unordered_set<int> uset{};

void dfs(int *nums) {
    for (int i = 0; i < N; ++i) {
        if (uset.find(nums[i]) != uset.end()) continue;
        tmp.push_back(nums[i]);
        uset.emplace(nums[i]);
        dfs(nums);
    }
    if (tmp.size() == N) ans.push_back(tmp);
    uset.erase(tmp.back());
    tmp.pop_back();
}

int main() {
    int n = 0;
    cin >> n;
    N = n;
    // 初始化数组
    int nums[n] = {};
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    dfs(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << setw(5) << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}