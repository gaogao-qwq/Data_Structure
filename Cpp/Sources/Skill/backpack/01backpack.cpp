#include <bits/stdc++.h>
using namespace std;

int N = 0, M = 0, maxValue = 0, weight = 0, value = 0;
vector<int> ans, tmp;
vector<pair<int, int>> items;

// 暴力做法：递归回溯
// 对于每个物品，有且仅有取和不取两种选择
// 将问题抽象成树，用 dfs 递归地去搜索所有可能
// 符合终止条件时，回溯至上一层递归
// 时间复杂度 O(2^n) （看这个时间复杂度你就知道铁 TLE 了，乖乖 dp 吧）
void dfs(int index) {
    // 递归终止条件（回溯条件）
    if (index >= N) return;
    if (weight + items[index].first > M) return;

    weight += items[index].first;
    value += items[index].second;
    tmp.push_back(index + 1);

    dfs(index + 1);

    // 如果当前取法价值大于最高价值，更新最高价值变量 maxValue 和取法记录数组 ans
    if (value > maxValue) {
        maxValue = value;
        ans = tmp;
    }
    // 回溯
    tmp.pop_back();
    weight -= items[index].first;
    value -= items[index].second;
}

// 其实在写上面的暴力递归的时候，我们不难发现
// 我们在遍历所有可能并求其价值和时，实际上出现了重复的子问题
// 遇到重复子问题，我们都可以考虑使用 dp 来降低时间复杂度开销
// 对于01背包，我们定义二维数组 dp[i][j] 为从下标为 [0 - i] 的物品里任意取，放进容量为 j 的背包的价值总和最大值
// 递推公式为 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
void dpSolution() {
    // dp 数组大小为 N * M + 1
    vector<vector<int>> dp(N, vector<int>(M + 1));
    // 初始化 dp 数组
    for (int j = items[0].first; j < M; ++j) {
        dp[0][j] = items[0].second;
    }

    // 遍历物品
    for(int i = 1; i < items.size(); i++) {
        // 遍历背包容量
        for(int j = 0; j <= M; j++) {
            if (j < items[i].first) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i].first] + items[i].second);
        }
    }

    // 打印
    cout << dp[items.size() - 1][M] << endl;
}

int main() {
    cin >> N >> M;
    items.resize(N);
    for (int i = 0; i < N; ++i) {
        int tmp1(0), tmp2(0);
        cin >> tmp1 >> tmp2;
        items[i] = make_pair(tmp1, tmp2);
    }
    // 遍历所有递归起点
    for (int i = 0; i < N; ++i) {
        dfs(i);
    }
    // 打印
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl << maxValue << endl;
    cout << "dpSolution:" << endl;
    dpSolution();
    return 0;
}
