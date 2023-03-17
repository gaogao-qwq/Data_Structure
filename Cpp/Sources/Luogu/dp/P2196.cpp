/* https://www.luogu.com.cn/problem/P2196 */
// 普及/提高- dp + dfs
// 难点：写递归要注意处理好回溯，以及读清楚题意
#include <bits/stdc++.h>
using namespace std;

// 维护一个全局变量 _max 和一个全局数组 path 用于存储答案
// 这里的临时 nums 数组实际上蕴含了 dp 的思想在其中
vector<int> path, tmp, nums;
int _max = 0, sum = 0, N = 0;

void dfs(int x, vector<vector<int>> &map) {
    tmp.push_back(x + 1);
    sum += nums[x];
    for (int i = 0; i < N - x - 1; ++i) {
        if (map[x][i] == 1) dfs(x + i + 1, map);
    }
    // 如果路径中炸弹数量和大于全局变量 _max，将全局数组 path 和变量 _max 都更新，然后回溯
    if (sum > _max) {
        _max = sum;
        path = tmp;
    }
    // 回溯
    tmp.pop_back();
    sum -= nums[x];
}

int main() {
    cin >> N;
    nums.resize(N);
    vector<vector<int>> map(N - 1, vector<int> (N - 1));
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            cin >> map[i][j];
        }
    }
    // 遍历所有起点
    for (int i = 0; i < N - 1; ++i) {
        dfs(i, map);
    }
    // 打印
    for (auto i : path) {
        if (i != path.back())
            cout << i << " ";
        else
            cout << i << endl;
    }
    cout << _max;
    return 0;
}